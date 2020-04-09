#include "bubbleSort.h"


void bubblesort ( int A[], int n )
{
    int i = 0;
    while (i<n)
    {
        for (size_t j = 0; j < n-i; j++)
        {
            if(A[j] < A[j+1])
            {
                int temp = A[j];
                A[i] = A[j+1];
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
