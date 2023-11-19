#include <iostream>
using namespace std;

void sort(int * arr, int size)
{
    for(int i = 1; i < size; i++)
    {
        for(int j = 0; j < size - i; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void print(int * arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int KthLargestelement(int * arr, int size, int k)
{
    sort(arr, size);

    return arr[size - k];
}

int KthSmallestelement(int * arr, int size, int k)
{
    sort(arr, size);

    return arr[k - 1];
}

int main()
{
    int size = 0;

    cout << "Enter the size of the array: ";

    cin >> size;

    int * arr = new int[size];

    for(int i = 0; i < size; i++)
    {
        cout << "Enter " << i << " th element: ";

        cin >> arr[i];
    }

    int k = 0;

    cout << "Enter K: ";

    cin >> k;

    if(k < size)
    {
        cout << "The " << k << "th largest element of the array is: " << KthLargestelement(arr, size, k);
        cout << endl;
        cout << "The " << k << "th smallest element of the array is: " << KthSmallestelement(arr, size, k);
    }
    else
    {
        cout << "K should not be bigger than array size";
    }

    
}