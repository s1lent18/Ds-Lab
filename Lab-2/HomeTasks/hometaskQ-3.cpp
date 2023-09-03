#include <iostream>
#include <string>
using namespace std;

class Recency
{
    public:
        int date;
        int month;
        int year;
        string nameofevent;

        void selectionsort(Recency * ptr, int size)
        {
            for (int i = 0; i < size - 1; i++)
            {
                int min = i;

                for (int j = i + 1; j < size; j++)
                {
                    if ((ptr[j].year < ptr[min].year) || (ptr[j].year == ptr[min].year && ptr[j].month < ptr[min].month) || ptr[j].year == ptr[min].year && ptr[j].month == ptr[min].month && ptr[j].date < ptr[min].date)
                    {
                        min = j;
                    }
                    
                }
                
                if(min != i)
                {
                    swap(ptr[i], ptr[min]);
                }

            }
            
        }

        void print(Recency * ptr, int size)
        {
            for (int i = 0; i < size; i++)
            {
                cout << "Name of the event: " << ptr[i].nameofevent << " and its date: " << ptr[i].date << "/" << ptr[i].month << "/" << ptr[i].year << endl;
            }
            
        }
};

int main()
{
    int size;

    do
    {
        cout << "Enter the number of events: " << endl;

        cin >> size;

    } while (size < 7 || size > 10);

    Recency * ptr = new Recency[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter the name of the event: ";

        cin >> ptr[i].nameofevent;

        cout << "Enter the year: ";
        
        cin >> ptr[i].year;

        do
        {
            cout << "Enter the month: ";

            cin >> ptr[i].month;

        } while (ptr[i].month < 1 || ptr[i].month > 12);
        
        if (ptr[i].month == 1 || ptr[i].month == 3 || ptr[i].month == 5 || ptr[i].month == 7 || ptr[i].month == 8 || ptr[i].month == 10 || ptr[i].month == 12)
        {
            do
            {
                cout << "Enter the date: ";
        
                cin >> ptr[i].date;

            } while (ptr[i].date < 1 || ptr[i].date > 31);

        } else if (ptr[i].month == 4 || ptr[i].month == 6 || ptr[i].month == 9 || ptr[i].month == 11)
        {
            do
            {
                cout << "Enter the date: ";
        
                cin >> ptr[i].date;

            } while (ptr[i].date < 1 || ptr[i].date > 30);
             
        } else
        {
            do
            {
                cout << "Enter the date: ";
        
                cin >> ptr[i].date;

            } while (ptr[i].date < 1 || ptr[i].date > 29);
        }
    }

    ptr->selectionsort(ptr, size);

    ptr->print(ptr, size);
    
}