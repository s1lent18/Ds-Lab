#include <iostream>
using namespace std;

void mergedesending(int * arr, int l, int c, int h)
{
    int size1 = c - l + 1;
    int size2 = h - c;

    int * arr1 = new int[size1];
    int * arr2 = new int[size2];

    for(int i = 0; i < size1; i++)
    {
        arr1[i] = arr[l + i];
    }

    for(int i = 0; i < size2; i++)
    {
        arr2[i] = arr[c + 1 + i];
    }

    int i = 0, j = 0, k = l;

    while(i < size1 && j < size2)
    {
        if(arr1[i] >= arr2[j])
        {
            arr[k] = arr1[i];
            i++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while(i < size1)
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }

    while(j < size2)
    {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}

void mergeascending(int * arr, int l, int c, int h)
{
    int size1 = c - l + 1;
    int size2 = h - c;

    int * arr1 = new int[size1];
    int * arr2 = new int[size2];

    for(int i = 0; i < size1; i++)
    {
        arr1[i] = arr[l + i];
    }

    for(int i = 0; i < size2; i++)
    {
        arr2[i] = arr[c + 1 + i];
    }

    int i = 0, j = 0, k = l;

    while(i < size1 && j < size2)
    {
        if(arr1[i] <= arr2[j])
        {
            arr[k] = arr1[i];
            i++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while(i < size1)
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }

    while(j < size2)
    {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}

void mergesortD(int * arr, int l, int h)
{
    if(l < h)
    {
        int c = l + (h - l) / 2;

        mergesortD(arr, l, c);
        mergesortD(arr, c + 1, h);

        mergedesending(arr, l, c, h);
    }
}

void mergesortA(int * arr, int l, int h)
{
    if(l < h)
    {
        int c = l + (h - l) / 2;

        mergesortA(arr, l, c);
        mergesortA(arr, c + 1, h);

        mergeascending(arr, l, c, h);
    }
}


int main()
{
    int size = 0; 

    int choice = 0;

    cout << "enter the size for your array: ";

    cin >> size;

    int * arr = new int[size];

    for(int i = 0; i < size; i++)
    {
        cout << "Enter " << i + 1 << "th Element: ";

        cin >> arr[i];
    }

    cout << "How do you want to sort ascending or desending: " << endl << "Enter 1 for ascending "<< endl <<"Enter 2 for desending" << endl;

    cin >> choice;

    if(choice == 1)
    {
        mergesortA(arr, 0, size - 1);
    }
    else
    {
        mergesortD(arr, 0, size - 1);
    }
    
    for(int i = 0; i < size; i++)
    {
        cout << i + 1 << "th :" << arr[i] << endl;
    }


}