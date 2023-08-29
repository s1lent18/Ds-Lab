#include <iostream>
#include <string>
#include <vector>
#include "HomeTask.h"
using namespace std;

int sizer = 0;

void Fast::getsize()
{
    cout << "Enter the number of departments: ";

    cin >> sizer;
    
    departments = new string * [sizer];

    number = new int [sizer];
}

void Fast::setCourses()
{    
    for (int i = 0; i < sizer; i++)
    {
        cout << "Enter the number of courses in this Department" << endl;

        cin >> number[i];
    }

    for (int i = 0; i < number[i]; i++)
    {
        departments[i] = new string[number[i]];
    }

    for (int j = 0; j < sizer; j++)
    {
        cout << "Enter the name of the courses of Dept " << j + 1 << endl;

        for (int k = 0; k < number[j]; k++)
        {
            cout << "Enter the name of that course " << endl;

            cin >> departments[j][k];
        } 
    }
        
}

void Fast::getCourses()
{
    for (int a = 0; a < sizer; a++)
    {
        cout << "Course List for Dept :" << a + 1 << endl;

        for (int b = 0; b < number[a]; b++)
        {
            cout << "Course " << b + 1 <<": " << departments[a][b] << "     ";
        }

        cout << endl;
        
    }
    
}