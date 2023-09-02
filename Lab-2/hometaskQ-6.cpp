#include <iostream>
#include <string>
using namespace std;

// Keeping in mind that we have low exchange cost relative to comparison cost 
// it it best to choose Selection Sort to minimize the number of exchanges 

class Time
{
    public:
        int seconds;
        int mins;
        int hrs;

        void Sort(Time * ptr, int size)
        {
            for(int i = 0; i < size - 1; i++)
            {
                int minindex= i;

                for(int j = i + 1; j < size; j++)
                {
                    if((ptr[j].hrs < ptr[j + 1].hrs) || (ptr[j].hrs == ptr[j + 1].hrs && ptr[j].mins < ptr[j + 1].mins) || (ptr[j].hrs == ptr[j + 1].hrs && ptr[j].mins == ptr[j + 1].mins && ptr[j].seconds < ptr[j + 1].seconds))
                    {
                        minindex = j;
                    }
                }
                if(minindex != i)
                {
                    swap(ptr[i], ptr[minindex]);
                }
            }  
        }

        void print(Time * ptr, int size)
        {
            for(int i = 0; i < size; i++)
            {
                cout << ptr[i].hrs << " : " << ptr[i].mins << " : " << ptr[i].seconds << endl;
            }
        }
};

int main()
{
    int size = 0;

    cin >> size;

    Time * ptr = new Time[size];

    for(int i = 0; i < size; i++)
    {
        do
        {
            cout << "Enter hours: ";

            cin >> ptr[i].hrs;

        } while (ptr[i].hrs < 0 || ptr[i].hrs > 23);

        do
        {
            cout << "Enter minutes: ";

            cin >> ptr[i].mins;

        } while (ptr[i].mins < 0 || ptr[i].mins > 59);

        do
        {
            cout << "Enter seconds: ";

            cin >> ptr[i].seconds;

        } while (ptr[i].seconds < 0 || ptr[i].seconds > 59);
  
    }

    ptr->Sort(ptr, size);

    ptr->print(ptr, size);
}