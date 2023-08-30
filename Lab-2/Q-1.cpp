#include <iostream>
using namespace std;

// best average worst time complexity = O(n^2)

// the only time, time complexity will be O(n) is when the array is already sorted 

void bubblesort(int * ptr, int size)
{
    for (int i = 1; i < size; i++)
    {
        for(int j = 0; j < size - i; j++)
        {
            if(ptr[j] > ptr[j + 1])
            {
                int temp = ptr[j];

                ptr[j] = ptr[j + 1];

                ptr[j + 1] = temp;
            }
        }
    }

    for(int i = 0; i < size; i++)
    {
        cout << i + 1 << ": " << ptr[i] << endl;
    }
}

int main()
{
    int * ptr = new int[10] {4, 5, 6, 9, 1, 3, 1, 4, 5, 7};

    bubblesort(ptr, 10);
}