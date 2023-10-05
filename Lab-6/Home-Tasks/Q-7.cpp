#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

int partition(int * arr, int left, int right)
{
    int pivot = arr[right];

    int i = left - 1;

    for(int j = left; j < right; j++)
    {
        if(arr[j] < pivot)
        {
            i++;

            swap(arr[j], arr[i]);
        }
    }

    swap(arr[i + 1], arr[right]);

    return i + 1;
}

void QuickSort(int * arr, int left, int right)
{
    if(left < right)
    {
        int pivot = partition(arr, left, right);

        QuickSort(arr, left, pivot - 1);

        QuickSort(arr, pivot + 1, right);
    }
}

int main()
{
    int timeQ = 0;
    int timeSQ = 0;

    for(int a = 0; a < 20; a++)
    {
        int * arr = new int[10000];

        for(int i = 0; i < 10000; i++)
        {
            arr[i] = rand() % 1001;
        }

        auto start = high_resolution_clock::now();

        QuickSort(arr, 0, 9999);

        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);

        timeQ += duration.count();
        
        start = high_resolution_clock::now();

        QuickSort(arr, 0, 9999);

        stop = high_resolution_clock::now();

        duration = duration_cast<microseconds>(stop - start);

        timeSQ += duration.count();

        delete []arr;
    }

    cout << "The average time for unsorted quicksort: " << (timeQ / 20) << endl;

    cout << "The average time for sorted quicksort: " << (timeSQ / 20) << endl;
}