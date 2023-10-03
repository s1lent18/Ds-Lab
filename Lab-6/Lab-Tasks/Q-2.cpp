#include <iostream>
using namespace std;

int returnMax(int * arr, int size)
{
    int max = 0;

    for(int i = 0; i < size; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void countSort(int * arr, int size, int exp)
{   
    int * output = new int[size];

    int count[10] = {0};

    for(int i = 0; i < size; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }

    for(int i = 1; i < 10; i++)
    {
        count[i] = count[i] + count[i - 1];
    }

    for(int i = size - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];

        count[(arr[i] / exp) % 10]--;
    }

    for(int i = 0; i < size; i++)
    {
        arr[i] = output[i];
    }
}

void countsortdesend(int * arr, int size, int exp)
{
    int * output = new int[size];

    int count[10] = {0};

    for(int i = 0; i < size; i++)
    {
        count[9 - (arr[i] / exp) %  10]++;
    }

    for(int i = 1; i < 10; i++)
    {
        count[i] = count[i] + count[i - 1];
    }

    for(int i = size - 1; i >= 0; i--)
    {
        output[count[9 - (arr[i] / exp) % 10] - 1] = arr[i];

        count[9 - (arr[i] / exp) % 10]--;
    }

    for(int i = 0; i < size; i++)
    {
        arr[i] = output[i];
    }
}

void RadixSort(int * arr, int size)
{
    int max = returnMax(arr, size);

    for(int exp = 1; max / exp > 0; exp *= 10)
    {
        countsortdesend(arr, size, exp);
    }
}

int main()
{
    int size = 0;

    cout << "Enter the size for your array: ";

    cin >> size;

    int * array = new int[size];

    for(int i = 0; i < size; i++)
    {
        cout << "Enter " << i + 1 << "th element: ";

        cin >> array[i];
    }

    RadixSort(array, size);

    cout << endl << "Sorting Array: " << endl;

    for(int i = 0; i < size; i++)
    {
        cout << i + 1 << ": " << array[i] << endl;
    }
}