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
                int curr = obj[a].eid, b = a - 1;

                while (obj[b].eid > curr && b >= 0)                             
                {
                    obj[b + 1].eid = obj[b].eid;
                    obj[b + 1].firstname = obj[b].firstname;
                    obj[b + 1].lastname = obj[b].lastname;
                    obj[b + 1].age = obj[b].age;
                    b--;
                }
                obj[b + 1].eid = curr; 
            }
        }

        void print(Employee obj[], int size)
        {
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

    //int s = (rand() % 4) += 7;

    const int size = 3;

    Employee obj[size];

    for (int  i = 0; i < size; i++)
    {
        cout << "First Name: " << endl;

        cin >> obj[i].firstname;

        cout << "Lastname: " << endl;

        cin >> obj[i].lastname;

        cout << "Age: " << endl;

        cin >> obj[i].age;

        cout << "Employee ID: " << endl;

        cin >> obj[i].eid;
    }
    obj->Insertion(obj, size);

    obj->print(obj, size);
}