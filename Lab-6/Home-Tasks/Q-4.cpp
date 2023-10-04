#include <iostream>
using namespace std;

int BinarySearch(int * arr, int size, int data)
{
    int l = 0, h = size - 1;

    while(l <= h)
    {
        int c = l + (h - 1) / 2;

        if(arr[c] == data)
        {
            return c;
        }
        else if(arr[c] > data)
        {
            h = c - 1;
        }
        else
        {
            l = c + 1;
        }
        
    }
    return -1;
}

int main()
{
    int size = 0;

    cout << "Enter the size of the array: ";

    cin >> size;

    int * arr = new int[size];

    for(int i = 0; i < size; i++)
    {
        cout << "Enter " << i + 1 << "th Element ";

        cin >> arr[i];
    }

    cout << BinarySearch(arr, size, 75);
}