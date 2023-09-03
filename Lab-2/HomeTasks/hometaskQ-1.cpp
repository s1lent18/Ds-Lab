#include <iostream>
#include <string>
using namespace std;

void bubblesort(string * ptr, int size)
{
    for (int i = 1; i < size; i++)
    {
        for(int j = 0; j < size - i; j++)
        {
            if(ptr[j] > ptr[j + 1])
            {
                string temp = ptr[j];

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
    int size = 0;

    cout << "Enter the desired Size for your array: " ;

    cin >> size;

    string * ptr = new string[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter " << i + 1 << " Element: ";

        cin >> ptr[i];
    }

    bubblesort(ptr, size);
}