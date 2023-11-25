#include <iostream>
using namespace std;

class Hash
{
    public:
        int data;
        int key;
};

class Map
{
    public:
        int size;
        Hash * arr;
        
        Map(int size)
        {
            this->size = size;;
            arr = new Hash[size];

            for(int i = 0; i < size; i++)
            {
                arr[i].key = -1;
                arr[i].data = 0;     
            }
        }

        void insert(int key)
        {
            int index = key % size;

            while(arr[index].key != -1)
            {
                index = (index + 1) % size;
            }

            arr[index].key = key;
            arr[index].data++;
        }

        int input(int key) 
        {
            int index = key % size;

            while (arr[index].key != key && arr[index].key != -1) 
            {
                index = (index + 1) % size;
            }

            return arr[index].data;
        }     
};

int Q2(int * arr, int size, int k)
{
    Map H(size);

    int ans = 0;

    for(int i = 0; i < size; i++)
    {
        int difference = k - arr[i];

        ans += H.input(difference);

        H.insert(arr[i]);
    }

    return ans;
}

int main() 
{
    int size = 0;

    int k = 0;

    cout << "Enter the size of the array and k: ";
    
    cin >> size >> k;

    int * array = new int[size];

    for(int i = 0; i < size; i++)
    {
        cout << "Enter " << i << " th Element: ";

        cin >> array[i];
    }

    int ans = Q2(array, size, k);

    cout << "Number of pairs with sum " << k << ": " << ans << endl;

    return 0;
}