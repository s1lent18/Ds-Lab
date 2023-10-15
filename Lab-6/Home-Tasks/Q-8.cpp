#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;

int Interpolation(int * arr,int l, int h, int data)
{
    int pos = 0;

    if(l <= h && data >= arr[l] && data <= arr[h])
    {
        pos = l + (((double)(h - l) / (arr[h] - arr[l])) * (data - arr[l]));

        if(arr[pos] == data)
        {
            return pos;
        }

        if(arr[pos] < data)
        {
            return Interpolation(arr, pos + 1, h, data);
        }

        if(arr[pos] > data)
        {
            return Interpolation(arr, l, pos - 1, data);
        }
    }
    return - 1;
}

int BinarySearch(int * arr, int size, int data)
{
    int l = 0, h = size - 1;

    while(l <= h)
    {
        int c = l + (h - l) / 2;

        if(arr[c] == data)
        {
            return c;
        }
        else if(arr[c] > data)
        {
            h = c - 1;
        }
        else if(arr[c] < data)
        {
            l = c + 1;
        }
    }
    return - 1;
}

float calculateuniformity(int * arr, int max)
{
    float deviation = 0.0f;

    int maximum = 0;

    int count = 0;

    for(int i = 0; i < 1000; i++)
    {
        count = 0;

        for(int j = 0; j < 1000; j++)
        {
            if(arr[i] == arr[j])
            {
                count++;
            }
        }
        if(count > maximum)
        {
            maximum = count;
        }
    }

    for(int i = 1; i < 101; i++)
    {
        count = 0;

        for(int j = 0; j < 1000; j++)
        {
            if(i == arr[j])
            {
                count++;
            }
        }

        deviation += (maximum - count);
    }
    
    return deviation / max;
}

void bubblesort(int * arr, int size)
{
    int count = 1;

    bool flag = false;

    while (count < size)
    {
        flag = false;

        for (int i = 0; i < (size - count); i++)
        {
            if (arr[i] > arr[i + 1])    
            {
                int temp = arr[i];      

                arr[i] = arr[i + 1];

                arr[i + 1] = temp;

                flag = true;
            }
            
        }

        if(flag == false)
        {
            break;
        }
        count++;
    }
}

int main()
{
    int size = 1000;

    int * arr = new int [size];

    srand(time(0));

    for(int i = 0; i < 1000; i++)
    {
        arr[i] = rand() % 101;
    }

    int max = -1, min = 101;

    for(int i = 0; i < 1000; i++)
    {
        if(max < arr[i])
        {
            max = arr[i];
        }
        else if(min > arr[i])
        {
            min = arr[i];
        }
    }

    bubblesort(arr, size);

    // for(int i = 0; i < 1000; i++)
    // {
    //     cout << arr[i] << endl;
    // }

    cout << "The Uniformity value of the array is " << calculateuniformity(arr, max) << endl;

    for(int i = 0; i < 60; i++)
    {
        auto start = high_resolution_clock::now();

        int search = rand() % 101;

        BinarySearch(arr, 1000, search);

        auto stop = high_resolution_clock::now();

        auto duration = duration_cast <nanoseconds> (stop - start);

        cout << "The time taken by binary Search is: " << duration.count() << endl;

        start = high_resolution_clock::now();

        Interpolation(arr, 0, 999, search);

        stop = high_resolution_clock::now();

        duration = duration_cast <nanoseconds> (stop - start);

        cout << "The time taken by Interpolation Search is: " << duration.count() << endl;
    }
}