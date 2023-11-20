#include <iostream>
using namespace std;

void maxheapcorrection(int * arr, int size, int index)
{
    int largest = index;
                                                                            
    int leftchild = 2 * index + 1;

    int rightchild = 2 * index + 2;

    if(leftchild < size && arr[leftchild] > arr[largest])
    {
        largest = leftchild;
    }

    if(rightchild < size && arr[rightchild] > arr[largest])
    {
        largest = rightchild;
    }

    if(largest != index)
    {
        swap(arr[largest], arr[index]);
        maxheapcorrection(arr, size, largest);
    }
}

void minheapcorrection(int * arr, int size, int index)
{
    int smallest = index;

    int leftchild = 2 * index + 1;

    int rightchild = 2 * index + 2;

    if(leftchild < size && arr[leftchild] < arr[smallest])
    {
        smallest = leftchild;
    }

    if(rightchild < size && arr[rightchild] < arr[smallest])
    {
        smallest = rightchild;
    }

    if(smallest != index)
    {
        swap(arr[smallest], arr[index]);
        minheapcorrection(arr, size, smallest);
    }
}

void printing(int * arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

int main()
{
    int size = 0;

    cin >> size;

    int * arr = new int[size];

    for(int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter K: ";

    int k = 0;

    cin >> k;

    for(int i = size/2 - 1; i >= k; i--)
    {
        maxheapcorrection(arr, size, i);
    }

    printing(arr, size);

    for(int i = size/2 - 1; i >= k; i--)
    {
        minheapcorrection(arr, size, i);
    }

    printing(arr, size);
}