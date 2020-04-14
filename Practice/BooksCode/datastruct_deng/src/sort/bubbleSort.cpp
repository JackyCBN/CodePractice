#include "bubbleSort.h"


void bubblesort ( int A[], int n )
{
    int i = 0;
    while (i<n-1)
    {
        for (size_t j = 0; j < n-i-1; j++)
        {
            if(A[j] > A[j+1])
            {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
        ++i;
    }    
}
void bubblesort1A ( int A[], int n )
{

}
void bubblesort1B ( int A[], int n )
{

}
void bubblesort2 ( int A[], int n )
{

}
