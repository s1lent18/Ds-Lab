#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <chrono>
#include <thread>
using namespace std;
using namespace std::chrono;

void bubblesort(int * arr)
{
    for(int i = 1; i < 900; i++)
    {
        for(int j = 0; j < 900 - i; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void merge(int * arr, int l, int c, int h)
{
    int size1 = c - l + 1;
    int size2 = h - c;

    int * arr1 = new int[size1];
    int * arr2 = new int[size2];

    for(int i = 0; i < size1; i++)
    {
        arr1[i] = arr[i + l];
    }

    for(int i = 0; i < size2; i++)
    {
        arr2[i] = arr[c + 1 + i];
    }

    int i = 0, j = 0, k = l;

    while(i < size1 && j < size2)
    {
        if(arr1[i] <= arr2[j])
        {
            arr[k] = arr1[i];
            i++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while(i < size1)
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }

    while(j < size2)
    {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}

void mergeSort(int * arr, int l, int h)
{
    if(l < h)
    {
        int c = l + (h - l) / 2;

        mergeSort(arr, l, c);
        mergeSort(arr, c + 1, h);
        merge(arr, l, c, h);
    }
}

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
    srand(time(0));

    int max1000Q = 0;
    int max1000M = 0;
    int min1000Q = 0;
    int min1000M = 0;
    int max100Q = 0;
    int max100M = 0;
    int min100Q = 0;
    int min100M = 0;

    int timeQ1000 = 0;
    int timeM1000 = 0;
    int timeQ100 = 0;
    int timeM100 = 0;


    for(int a = 0; a < 20; a++)
    {
        int * arr1 = new int[1000];
        int * arr2 = new int[1000];
        int * arr3 = new int[1000];
        int * arr4 = new int[1000];
        int * arr5 = new int[1000];

        for(int i = 0; i < 1000; i++)
        {
            arr1[i] = rand() % 101;
        }

        for(int i = 0; i < 1000; i++)
        {
            arr2[i] = arr1[i];
            arr3[i] = arr1[i];
        }

        auto start = high_resolution_clock::now();

        QuickSort(arr1, 0, 999);

        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);

        cout << "The time taken to sort 1000 elements using QuickSort: " << duration.count() << " microseconds " << endl;

        timeQ1000 += duration.count();

        start = high_resolution_clock::now();

        mergeSort(arr2, 0, 999);

        stop = high_resolution_clock::now();

        duration = duration_cast<microseconds>(stop - start);

        cout << "The time taken to sort 1000 elements using MergeSort: " << duration.count() << " microseconds " << endl;
    
        timeM1000 += duration.count();

        bubblesort(arr3);

        for(int i = 0; i < 1000; i++)
        {
            arr4[i] = arr3[i];
            arr5[i] = arr3[i];
        }
        start = high_resolution_clock::now();

        QuickSort(arr5, 0, 999);

        stop = high_resolution_clock::now();

        duration = duration_cast<microseconds>(stop - start);

        cout << "The time taken to sort 100 elements using quicksort: " << duration.count() << " microseconds " << endl;
        
        timeQ100 += duration.count();

        start = high_resolution_clock::now();
        
        mergeSort(arr4, 0, 999);

        stop = high_resolution_clock::now();

        duration = duration_cast<microseconds>(stop - start);

        cout << "The time taken to sort 100 elements using mergesort: " << duration.count() << " microseconds " << endl;

        timeM100 += duration.count();

        delete []arr1;
        delete []arr2;
        delete []arr3;
        delete []arr4;
        delete []arr5;
    }

    cout << "The average time taken by quicksort sorting 1000 elements: " << (timeQ1000 / 20) << endl;

    cout << "The average time taken by mergesort sorting 1000 elements: " << (timeM1000 / 20) << endl;

    cout << "The average time taken by quicksort sorting 100 elements: " << (timeQ100 / 20) << endl;

    cout << "The average time taken by mergesort sorting 100 elements: " << (timeM100 / 20) << endl;

}   