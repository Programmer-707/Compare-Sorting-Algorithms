#ifndef MERGE_SORT_H_INCLUDED
#define MERGE_SORT_H_INCLUDED

void Merge(int *A, int B[], int low, int mid, int high)
{
    int i = low, j = mid+1, k = low;
   // int *B = new int[high+1];

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k++] = A[i++];
        }
        else
        {
            B[k++] = A[j++];
        }
    }
    while (i <= mid)
    {
        B[k++] = A[i++];
    }
    while (j <= high)
    {
        B[k++] = A[j++];
    }
    for (int i=low; i<=high; i++)
    {
        A[i] = B[i];
    }
}

void MergeSort(int *A, int low, int high)
{

    if (low < high)
    {
        // Calculate mid point
        int mid = (high+low)/2;

        // Sort sub-lists
        MergeSort(A, low, mid);
        MergeSort(A, mid+1, high);

        // Merge sorted sub-lists
        int *b = new int [high+1];
        Merge(A, b, low, mid, high);
    }
}


#endif // MERGE_SORT_H_INCLUDED
