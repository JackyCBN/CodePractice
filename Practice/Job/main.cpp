#include <iostream>
#include <thread>
#include <queue>
#include <atomic>
#include <mutex>

using namespace std;

void singleThreadTest()
{

}
const int testCount = 20000;
const int jobCount = 100;
//#define LOG_ENABLE 1
struct taskData
{
    int loopCount;
    int index;
    void* pData;
    int startPoint;
    int nums;
};

struct schedulerContext
{
    int threadNums;
    std::thread threads[1000];
    int taskResults[1000];
    std::mutex globalTaskQueueMutex;
    std::queue<taskData> globalTaskQueue;
    std::atomic<bool> threadShouldRun;
    std::condition_variable cv;
};


schedulerContext gContext;
struct workerData
{

};


void LockSynchronizationPrimitive()
{
    gContext.globalTaskQueueMutex.lock();
}

void UnlockSynchronizationPrimitive()
{
    gContext.globalTaskQueueMutex.unlock();
}
int testCountBySequence(int begin ,int count)
{
    int total = 0;
    for(int i=0; i<count; i++)
    {
            total += (i + begin);
    }
    return total;
}
void Execute(taskData& task)
{
    gContext.taskResults[task.index] = testCountBySequence(task.startPoint, task.loopCount);
}

void WaitUntilTaskIsAvailable()
{
    std::unique_lock<std::mutex> lock(gContext.globalTaskQueueMutex);
    gContext.cv.wait(lock, []{return !gContext.globalTaskQueue.empty();});
}
void WorkOnTasks( int index)
{
    //cout<<"WorkOnTasks ..."<<endl;

    while (gContext.threadShouldRun)
    {
        cout<<"WorkOnTasks ..."<<index<<endl;
        WaitUntilTaskIsAvailable();
        
cout<<"WorkOnTasks after wait..."<<index<<endl;
        taskData task;
        LockSynchronizationPrimitive();

        if(!gContext.globalTaskQueue.empty())
        {
                task = gContext.globalTaskQueue.front();
                gContext.globalTaskQueue.pop();
                gContext.threadShouldRun = !gContext.globalTaskQueue.empty();
                #ifdef LOG_ENABLE
                std::cout<<"run task : " << task.index <<endl;
                #endif
        }

        UnlockSynchronizationPrimitive();
        
        Execute(task);
    }
}

void CreateWorkerThreads(schedulerContext* pContext)
{
    //cout<<"CreateWorkerThreads ..."<<endl;
    for(int i=0; i<pContext->threadNums; ++i)
    {
        //pContext->threads[i] = std::thread(work_test, i);
        pContext->threads[i] = std::thread(WorkOnTasks, i);

    }
}

void WaitUntilTasksAreFinished(schedulerContext* pContext)
{
    cout<<"WaitUntilTasksAreFinished ..."<<endl;

    for(int i=0; i<pContext->threadNums; ++i)
    {
        cout<<"finish 00 " <<i<<endl;
        pContext->threads[i].join(); //?
        cout<<"finish " <<i<<endl;
    }
}

void AddTaskToScheduler(taskData task)
{
    #ifdef LOG_ENABLE
    cout<<"AddTaskToScheduler ... index: " << task.index<<endl;
   #endif
     LockSynchronizationPrimitive();
  gContext.globalTaskQueue.push(task);
  UnlockSynchronizationPrimitive();
  gContext.cv.notify_one();
}


void jobTest(schedulerContext* pContext)
{
    // create work thread
        // wait startup
    CreateWorkerThreads(pContext);
    int count = jobCount;
    int gap = testCount / count;

    for(int i=0; i<count; ++i)
    {
        taskData t;
        t.loopCount = gap;
        t.index = i;
        t.nums = (i == count-1) ? testCount - i-gap : gap;

        AddTaskToScheduler(t);
    }
    // add job

    // waitfor job to

    WaitUntilTasksAreFinished(pContext);
}


int main()
{
    

     gContext.threadNums = thread::hardware_concurrency();
     gContext.threadShouldRun = true;
    cout<<"Start Test: [Single Thread]"<<endl;
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    int result = testCountBySequence(0, testCount);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
    cout<<"End Test: [Single Thread] " << result<<endl;

    cout<<"Start Job Test"<<endl;
    //tickFrame();
     begin = std::chrono::steady_clock::now();
     int result2 = 0;
     jobTest(&gContext);
     for(int i=0; i!=jobCount; i++)
     {
        result2 += gContext.taskResults[i];
     }
end = std::chrono::steady_clock::now();
std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
       
    cout<<"End  Job Test result2: "<<result2<<endl;
    return 0;
}