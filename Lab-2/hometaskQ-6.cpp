#include <iostream>
#include <string>
using namespace std;

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
                    minindex = j;
                }
                if(minindex != i)
                {
                    swap(ptr[i], ptr[minindex]);
                }
            }

            
        }
};