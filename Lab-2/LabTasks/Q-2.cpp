#include <iostream>
using namespace std;

void Insertion(int * ptr, int size)
{
    for(int a = 1; a < size; a++)
    {
        int curr = ptr[a], b = a - 1;

        while (ptr[b] < curr && b >= 0)                             
        {
            ptr[b + 1] = ptr[b];

            b--;
        }
        ptr[b + 1] = curr; 
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

    Insertion(ptr, size);
}