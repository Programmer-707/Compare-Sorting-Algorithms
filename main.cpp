#include <iostream>
#include <chrono>
#include <random>
#include <fstream>
#include <iomanip>
#include "quick_sort.h"
#include "merge_sort.h"
#include "heap_sort.h"

using namespace std;

int main()
{
    using chrono::nanoseconds;
    random_device rd;
    mt19937 gen(rd());

    int start = 10;
    int max_size = 5000; // max size of array
    int times = 100;
    int step = 60;
    int rand_num = 10000;

    //Set the random distribution
    uniform_int_distribution<int> dist(0, rand_num);

    auto begin = chrono::steady_clock::now();
    auto end = chrono::steady_clock::now();

    nanoseconds total_heap(0), average_heap(0);
    nanoseconds total_quick(0), average_quick(0);
    nanoseconds total_merge(0), average_merge(0);

    cout << " Size " << setw(10)
         << " Heap Sort " << setw(10)
         << " Quick Sort " << setw(10)
         << " Merge Sort " << endl;
    cout << "=================================================================================\n";

    for (int N = start; N < max_size; N = N + step)
    {
        int* heap_arr = new int [N];
        int* merge_arr = new int [N];
        int* quick_arr = new int [N];
        int* temp = new int [N];

        for(int t = 0; t < times; t++)
        {

            for(int i=0; i<N; i++)
            {
                temp[i] = dist(gen);
            }

            for(int i=0; i<N; i++)
            {
                heap_arr[i] = temp[i];
                merge_arr[i] = temp[i];
                quick_arr[i] = temp[i];
            }

            begin = std::chrono::steady_clock::now();
            HeapSort(heap_arr,N);
            end = chrono::steady_clock::now();
            nanoseconds time_heap(end - begin);
            total_heap += time_heap;

            begin = std::chrono::steady_clock::now();
            QuickSort(quick_arr, 0, N-1);
            end = chrono::steady_clock::now();
            nanoseconds time_quick(end - begin);
            total_quick += time_quick;

            begin = std::chrono::steady_clock::now();
            MergeSort(merge_arr, 0, N-1);
            end = chrono::steady_clock::now();
            nanoseconds time_merge(end - begin);
            total_merge += time_merge;
        }

        average_heap = total_heap / times;
        average_quick = total_quick / times;
        average_merge = total_merge / times;

        cout << N << setw(15)
             << average_heap.count() << " ns" << setw(15)
             << average_quick.count() << " ns" << setw(15)
             << average_merge.count() << " ns" <<endl;

        delete [] merge_arr;
        delete [] heap_arr;
        delete [] quick_arr;
        delete [] temp;
    }

    return 0;
}
