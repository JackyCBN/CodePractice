#include <iostream>
#include <thread>
#include <queue>
#include <atomic>
#include <mutex>

using namespace std;

void singleThreadTest()
{

}
const int testCount = 1000000000;
struct taskData
{
    int loopCount;
    int index;
    void* pData;
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
int testCountBySequence(int count)
{
    int total = 0;
    for(int i=0; i!=count; i++)
    {
            total += 1;
    }
    return total;
}
void Execute(taskData& task)
{
    gContext.taskResults[task.index] = testCountBySequence(task.loopCount);
}

void WaitUntilTaskIsAvailable()
{

}
void WorkOnTasks( int index)
{
    //cout<<"WorkOnTasks ..."<<endl;

    while (gContext.threadShouldRun)
    {
        WaitUntilTaskIsAvailable();
        

        taskData task;
        LockSynchronizationPrimitive();

        if(!gContext.globalTaskQueue.empty())
        {
                task = gContext.globalTaskQueue.front();
                gContext.globalTaskQueue.pop();
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
        pContext->threads[i].join(); //?
    }
}

void AddTaskToScheduler(taskData task)
{
    cout<<"AddTaskToScheduler ..."<<endl;
     LockSynchronizationPrimitive();
  gContext.globalTaskQueue.push(task);
  UnlockSynchronizationPrimitive();
}


void jobTest(schedulerContext* pContext)
{
    // create work thread
        // wait startup
    CreateWorkerThreads(pContext);

    for(int i=0; i<pContext->threadNums; ++i)
    {
        taskData t;
        t.nums = 100 + i;
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

    cout<<"Start Job Test"<<endl;
    //tickFrame();
    jobTest(&gContext);
    cout<<"End  Job Test"<<endl;
    cout << "Hello World"<<endl;
    return 0;
}