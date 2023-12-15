#include <iostream>
using namespace std;

class HashTable
{
    public:
        int * data;
        int size;

        HashTable(int size)
        {
            data = new int[size];
            this->size = size;

            for(int i = 0; i < size; i++)
            {
                data[i] = -1;
            }
        }

        int HashFormula(int val)
        {
            return val % size;
        }

        void insert(int val)
        {
            int index = HashFormula(val);

            if(data[index] == -1)
            {
                data[index] = val;
            }
        }
};

int sizeofHash(HashTable T)
{
    int siz = 0;

    for(int i = 0; i < T.size; i++)
    {
        if(T.data[i] != -1)
        {
            siz++;
        }
    }
    return siz;
}

int Q5(int * target, int tsize, int * arr, int asize)
{
    HashTable B(tsize);

    HashTable A(tsize + asize);

    for(int i = 0; i < tsize; i++)
    {
        B.insert(arr[i]);

        A.insert(arr[i]);
    }

    for(int i = 0; i < tsize; i++)
    {
        A.insert(target[i]);
    }

    return sizeofHash(A) - sizeofHash(B);
}

int main()
{
    int tsize = 0, asize = 0;

    cout << "Enter the size of your target array and original array: ";

    cin >> tsize >> asize;

    int * target = new int[tsize];

    int * arr = new int[asize];

    for(int i = 0; i < tsize; i++)
    {
        cout << "Enter the " << i << " th element for target array: ";

        cin >> target[i];
    }

    for(int i = 0; i < asize; i++)
    {
        cout << "Enter the " << i << " th element for original array: ";

        cin >> arr[i];
    }

    cout << Q5(target, tsize, arr, asize);
}