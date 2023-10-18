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

        string print()
        {
            string prin;

            for(int i = 0; i < size; i++)
            {
                prin += Top();

                pop();
            }
            return prin;
        }


};

void postfix(char * input)
{
    string a = input;

    Stack S(a.length());

    bool flag = false;
    char op;

    for(int i = 0; i < a.length(); i++)
    {
        if(input[i] >= 'a' && input[i] <= 'z')
        {
            S.push(input[i]);
            if(flag == true)
            {
                flag = false;
                S.push(op);
            }
        }
        else if(input[i] == '(' || input[i] == ')')
        {
            continue;
        }
        else
        {
            op = input[i];
            flag = true;
        }
    }

    string p =  S.print();

    for(int i = p.size() - 1; i >= 0; i--)
    {
        cout << p[i];
    }
}

int main()
{
    char * n = new char[7];
    
    for(int i = 0; i < 7; i++)
    {
        cin >> n[i]; 
    }
    postfix(n);
}