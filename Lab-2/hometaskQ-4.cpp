#include <iostream>
#include <time.h>
using namespace std;

class Employee
{
    public:
        string firstname;
        string lastname;
        int age;
        int eid;

        Employee()
        {

        };
        Employee(string firstname, string lastname, int age, int eid)
        {
            this->firstname = firstname;
            this->lastname = lastname;
            this->age = age;
            this->eid = eid;
        }

        void Insertion(Employee obj[], int size)
        {
            for(int a = 1; a < size; a++)
            {
                int currid = obj[a].eid;
                string currf = obj[a].firstname;
                string currl = obj[a].lastname;
                int currage = obj[a].age;
                int b = a - 1;

                while (obj[b].eid > currid && b >= 0)                             
                {
                    obj[b + 1].eid = obj[b].eid;
                    obj[b + 1].firstname = obj[b].firstname;
                    obj[b + 1].lastname = obj[b].lastname;
                    obj[b + 1].age = obj[b].age;
                    b--;
                }
                obj[b + 1].eid = currid;
                obj[b + 1].firstname = currf;
                obj[b + 1].lastname = currl;
                obj[b + 1].age = currage;
            }
        }

        void print(Employee obj[], int size)
        {
            cout << "The Sorted List of Employees according to Their Employee ID's: " << endl << endl;

            for (int i = 0; i < size; i++)
            {
                cout << "First Name: " << obj[i].firstname << endl;
                cout << "Lastname: " << obj[i].lastname << endl;
                cout << "Age: " << obj[i].age << endl;
                cout << "Employee ID: " << obj[i].eid << endl;
            }
            
        }

};

int main()
{
    srand(time(0));

    int input;

    do
    {
        cout << "Enter the number of Employees: " << endl;

        cin >> input;

    } while (input < 7 || input > 10);

    const int size = input;

    int a = 0;

    Employee obj[size];

    int arr[size];

    for (int  i = 0; i < size; i++)
    {
        cout << "First Name: " << endl;

        cin >> obj[i].firstname;

        cout << "Lastname: " << endl;

        cin >> obj[i].lastname;
        
        cout << "Age: " << endl;

        cin >> obj[i].age;
        
        if(i == 0)
        {
            cout << "Employee ID: " << endl;

            cin >> obj[i].eid;

            arr[a] = obj[i].eid;

            a++;

        }else
        {
            unique:
                int temp;

                cout << "Employee ID: " << endl;

                cin >> obj[i].eid;

                for (int j = 0; j < size; j++)
                {
                    if (arr[j] == obj[i].eid)
                    {
                        goto unique;
                    }    
                }
                arr[a] = obj[i].eid;

                a++;
        }
        
    }
    obj->Insertion(obj, size);

    obj->print(obj, size);
}