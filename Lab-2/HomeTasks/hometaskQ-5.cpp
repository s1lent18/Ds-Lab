#include <iostream>
#include <string>
using namespace std;

void function(int  ptr[], int size)
{
    int  pointer[size];

    for(int i = 0; i < size; i++)
    {
        pointer[i] = ptr[i];
    }
    
    int min, max, n = size - 1;

    for(int i = 1; i < size; i++)
    {
        for(int j = 0; j < size - i; j++)
        {
            if(pointer[j] > pointer[j + 1])
            {
                int temp = pointer[j];

                pointer[j] = pointer[j + 1];

                pointer[j + 1] = temp;
            }
        }
    }

    for(int i = 0; i < size; i++)
    {
        if(ptr[i] != pointer[i])
        {
            min = i;

            break;
        }
    }   

    for(int j = n; j >= 0; j--)
    {
        if(ptr[j] != pointer[j])
        {
            max = j;

            break;
        }
    }

    cout << "The subarray lies between indexes " << min << " and " << max << endl;

}

int main()
{
    int size;

    cout << "Enter the number of elements: ";

    cin >> size;

    int * ptr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> ptr[i];
    }

    function(ptr, size);
    
}