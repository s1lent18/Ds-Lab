#include <iostream>
using namespace std;

int Fibonacci(int number)
{
    if(number == 0 || number == 1)
    {
        return number;
    }

    return Fibonacci(number - 1) + Fibonacci(number - 2);
}

int main()
{
    int num;

    cout << "Enter the number till you want to generate the fabonacci series: ";

    cin >> num;

    for(int i = 0; i < num; i++)
    {
        cout << Fibonacci(i) << ", ";
    }

}