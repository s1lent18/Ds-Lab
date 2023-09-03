#include <iostream>
using namespace std;

void bestcase(int * ptr, int size)
{
    bool flag = true;

    for (int i = 0; i < size - 1; i++)
    {
        if(ptr[i + 1] < ptr[i])
        {
            flag = false;
        }
        if(!flag)
        {   
            cout << "Not the best case senario" << endl;

            return;
        } 
    }
    cout << "Best case Senario " << endl;
    
}

int main()
{
    int size = 0;

    cout << "Enter the desired size of the array: ";

    cin >> size;

    int * ptr = new int[size];

    for(int i = 0; i < size; i++)
    {
        cout << "Enter " << i + 1 << " Element: ";

        cin >> ptr[i]; 
    }

    bestcase(ptr, size);
}