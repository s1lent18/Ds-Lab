#include <iostream>
#include <string>
using namespace std;

void function(int * ptr, int size)
{
    int * pointer = ptr;
    
    int min, max, n = size - 1, minindex, maxindex, temp;

    for (int i = 0; i < size; i++)
    {
        if (ptr[i] > ptr[i + 1])
        {
            min = ptr[i + 1];

            temp = ptr[i];

            break;
        }
    }

    for(int i = n; i > 0; i--)
    {
        if(ptr[i] < ptr[i - 1]  && ptr[i - 1] != temp) /////
        {
            max = ptr[i - 1];
        }
    }

    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < size - i; j++)
        {
            if (pointer[j] > pointer[j + 1])
            {
                int temp = pointer[j];

                pointer[j] = pointer[j + 1];

                pointer[j + 1] = temp;
            }   
        }
    }

    for(int i = 0; i < size; i++)
    {
        if (pointer[i] == min)
        {
            minindex = i;
        }

        if (pointer[i] == max)
        {
            maxindex = i;
        }
    }
    
    cout << maxindex << " --- " << minindex << endl;
    
}

int main()
{
    int * ptr = new int[9];

    for (int i = 0; i < 9; i++)
    {
        cin >> ptr[i];
    }

    function(ptr, 9);
    
}