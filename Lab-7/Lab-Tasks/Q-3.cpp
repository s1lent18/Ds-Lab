#include <iostream>
#include <cmath>
using namespace std;

class Stack
{
    private:
        char * arr;
        int top;
        int size;

    public:
        Stack(int size)
        {
            this->size = size;
            arr = new char [size];
            top = -1;
        }

        void push(char element)
        {
            if(top == size - 1)
            {
                cout << "Stack OverFlow " << endl;

                return;
            }

            top += 1;
            arr[top] = element;
        }

        void pop()
        {
            if(top == - 1)
            {
                cout << "Stack Empty no element to pop " << endl;

                return;  
            }

            top -= 1;
        }

        char Top()
        {
            if(top == - 1)
            {
                cout << "Stack Empty no element to pop " << endl;

                return '0';
            }

            return arr[top];
        }

        bool empty()
        {
            return top == -1;
        }

};

bool checkpre(char op)
{
    if(op == '+' || op == '-')
    {
        return 0;
    }
    else if(op == '*' || op == '/')
    {
        return 1;
    }
}

string postfix(string input)
{
    Stack S(input.length());

    string convert;

    for(int i = 0; i < input.length(); i++)
    {
        if(input[i] >= 'a' && input[i] <= 'z')
        {
            convert += input[i];
        }
        else if(input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
        {
            S.push(input[i]);
        }
        else if(input[i] == '(')
        {
            S.push(input[i]);
        }
        else if(input[i] == ')')
        {
            while(!S.empty() && S.Top() != '(')
            {
                convert += S.Top();
                S.pop();
            }
            S.pop();
        }
    }

    while(!S.empty())
    {
        convert += S.Top();
        S.pop();
    }
    return convert;
}

int main()
{
    string input = "((a+b)*c)-d";
    cout << postfix(input) << endl;
}