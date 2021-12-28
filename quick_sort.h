#ifndef QUICK_SORT_H_INCLUDED
#define QUICK_SORT_H_INCLUDED

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// First Element is Pivot
int partition(int A[], int low, int high)
{
    // first element as pivot
    int pivot = A[low];
    int i = low + 1; // index i which is in second element of array
    int j = high;   // index j last element of array

    while (true)
    {
        // loop for finding the elements which are greater than pivot
        // in this loop, i should move as long as the elements are smaller or equal to pivot
        // when the element is greater than pivot it should stop
        while (i <= j && A[i] <= pivot)
        {
            i++;
        }
        // loop for finding the elements which are smaller than pivot
        // in this loop, i should move as long as the elements are greater or equal to pivot
        // when the element is smaller than pivot it should stop decrementing
        while (A[j] >= pivot && j >= i)
        {
            j--;
        }
        // when both of loops above stops, then check if j is less than i means elements which are in array, are sorted
        // except pivot, if not then swap the elements
        if (j < i)
        {
            break;
        }
        else
        {
            swap(&A[i], &A[j]);
        }
    }
    // after comparing elements with pivot and swapping them are done,
    // we need to swap the pivot with element which is less than pivot
    swap(&A[low], &A[j]);

    // return j which is partitioning position
    return j;
}

void QuickSort(int A[], int low, int high)
{
    if (low < high)
    {
        int p = partition(A, low, high);
        QuickSort(A, low, p-1);
        QuickSort(A, p+1, high);
    }
}

#endif // QUICK_SORT_H_INCLUDED
