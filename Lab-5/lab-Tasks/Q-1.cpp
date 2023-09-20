#include <iostream>
using namespace std;

int square(int number, int count)
{
    if(count == 0)
    {
        return 0;
    }
    else
    {
        return number + square(number, count - 1);
    }
    
}

int main()
{
    int limit = 0;

    cout << "Enter the number till you want square: " ;

    cin >> limit;

    for(int i = 1; i <= limit; i++)
    {
        cout << square(i, i) << ", " ;
    }
}