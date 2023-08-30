#include <iostream>
using namespace std;

void Selection(int * ptr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;

        for (int j = i + 1 ; j < size; j++)
        {   
            if(ptr[j] < ptr[min])
            {
                min = j;
            }
        }

        if(min != i)
        {
            int temp = ptr[min];

            ptr[min] = ptr[i];

            ptr[i] = temp;
        }
    }
    
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << ": " << ptr[i] << endl;
    }
}

int main()
{
    int size = 0;

    cout << "Enter the desired size for your array: " << endl;

    cin >> size;

    int * ptr = new int[size];

    for(int i = 0; i < size; i++)
    {
        cout << "Enter " << i + 1 << " Element: ";

        cin >> ptr[i]; 
    }

    Selection(ptr, size);
}