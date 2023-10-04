#include <iostream>
using namespace std;

int divide(int * array, int left, int right)
{
    int p = array[right];

    int i = left - 1;

    for(int j = left; j < right; j++)
    {
        if(array[j] < p)
        {
            i++;

            swap(array[j], array[i]);
        }
    }

    swap(array[i + 1], array[right]);

    return i + 1;
}

void QuickSort(int * arr, int left, int right)
{
    if(left < right)
    {
        int p = divide(arr, left, right);

        QuickSort(arr, left, p - 1);

        QuickSort(arr, p + 1, right);
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

    QuickSort(array, 0, size - 1);

    cout << endl << "Sorting Array: " << endl;

    for(int i = 0; i < size; i++)
    {
        cout << i + 1 << ": " << array[i] << endl;
    }
}
