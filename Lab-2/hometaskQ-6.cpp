#include <iostream>
#include <string>
using namespace std;

// Keeping in mind that we have low exchange cost relative to comparison cost 
// it it best to choose Selection Sort to minimize the number of exchanges 

class Time
{
    public:
        int hrs;
        int index;

        void Sort(Time * ptr, int size)
        {
            for(int i = 0; i < size - 1; i++)
            {
                int minindex = i;

                for(int j = i + 1; j < size; j++)
                {
                    if((ptr[j].hrs < ptr[minindex].hrs))
                    {
                        minindex = j;
                    }
                }
                if(minindex != i)
                {
                    swap(ptr[minindex], ptr[i]);
                }
            }  
        }

        void print(Time * ptr, int size)
        {
            for(int i = 0; i < size; i++)
            {
                cout << "The Time left for the delivery of crate " << ptr[i].index << " is " << ptr[i].hrs << " hours " << endl;
            }
        }
};

int main()
{
    int size = 0;

    cout << "Enter size: " << endl;

    cin >> size;

    Time * ptr = new Time[size];

    for(int i = 0; i < size; i++)
    {
        cout << "Enter hours left for delivery of crate " << i << ": ";

        cin >> ptr[i].hrs;

        ptr[i].index = i + 1;
    }

    ptr->Sort(ptr, size);

    ptr->print(ptr, size);
}