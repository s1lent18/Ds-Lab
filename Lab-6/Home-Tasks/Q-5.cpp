#include <iostream>
using namespace std;

int Interpolation(int * arr, int l, int h, int data)
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

    cout << Interpolation(arr, 0, size - 1, 34);
}