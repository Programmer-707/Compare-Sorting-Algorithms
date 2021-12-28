#ifndef HEAP_SORT_H_INCLUDED
#define HEAP_SORT_H_INCLUDED

// in binary heap we always insert new element to last node
void Insert(int *A,int n) // inserting elements to the binary tree
{
    int i = n,temp;  // n is the last place of the array where newly inserted values are there
    temp = A[i];     // assigning the last element to the temporary value which is temp in order to compare with elements of the array

    // while loop, condition: i should be till 1  why not 0 because
    // I created array with the first element takes the first place (index 0)
    // binary heap starts from first index (index 1) so thats why 0 takes place very first place of the array
    while(i>1 && temp > A[i/2])
    {
        // i/2 -> means its parent of elements with index i
        // if temp, which is newly inserted value, greater than its parent
        // we need to swap elements which are newly inserted value and its parent
        A[i] = A[i/2];
        i = i/2;
    }

    A[i] = temp; // after comparing and swapping we need to assign temp in the proper place in the binary heap
}

// Actually heap sorting we need to delete all the values from binary heap and
// every deleting values should restore to the array step by step.
// while deleting process, we always have to delete the root first in binary heap
int HeapSort(int *A,int n)
{
    // first of all, we have to insert all the elements to binary heap with Insert() function
    for(int q=2; q<=n-1; q++)
        Insert(A, q);

    // i = index of parent,
    // j = index of child, x for taking the last element
    // temp for swapping,
    int i, j, x, temp, val;
    for(int d=n-1; d>1; d--)
    {

        val = A[1];    // removing the root from binary heap with assigning to value val
        x = A[d];
        A[1] = A[d]; // then we need to move the last element to the root
        A[d] = val; // removed root should be store to the last place of the array
        i = 1;     // root assigning to i value
        j = i*2;  // left child of root j

        // loop works till taking the all elements from the binary heap
        while(j <= d-1)
        {
            // condition for comparing the children
            // condition if right child A[j+1] greater than left child A[j] then increment the j means move from left child right child
            if(j < d-1 && A[j+1] > A[j])
                j = j+1;

            // condition for comparing parent and its child which is greater one
            // if child is greater than its parent then swap the elements
            if(A[i] < A[j])
            {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
                i = j;    // also move the parent index
                j = 2*j; // left child of next parent
            }
            else
                break;
        }
    }
    return val;
}


#endif // HEAP_SORT_H_INCLUDED
