#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

class Nodei
{
    public:
        int data;
        Nodei * next;

        Nodei()
        {

        };

        Nodei(int data)
        {
            this->data = data;
            next = NULL;
        }
};

class Nodec
{
    public:
        char data;
        Nodec * next;

        Nodec()
        {
            next = NULL;
        };

        Nodec(char data)
        {
            this->data = data;
            next = NULL;
        }
};

class LinkedListc
{
    public:
        Nodec * head;

        void insertathead(char value)
        {
            Nodec * n = new Nodec(value);

            n->next = head;

            head = n;

            return;
        }

        void deleteathead()
        {
            Nodec * del = head;

            head = head->next;

            del = NULL;

            delete del;
        }

        char last()
        {
            return head->data;
        }
};

class LinkedListi
{
    public:
        Nodei * head;

        void insertathead(int value)
        {
            Nodei * n = new Nodei(value);

            n->next = head;

            head = n;

            return;
        }

        void deleteathead()
        {
            Nodei * del = head;

            head = head->next;

            del = NULL;

            delete del;
        }

        int last()
        {
            return head->data;
        }
};

class Stackc
{
    public:
        LinkedListc * L = new LinkedListc();

        void push(char value)
        {
            L->insertathead(value);
        }

        void pop()
        {
            if(L->head == NULL)
            {
                return;
            }
            L->deleteathead();
        }

        char Top()
        {
            return L->last();
        }

        bool isempty()
        {
            if(L->head == NULL)
            {
                return true;
            }
            return false;
        }
};

class Stacki
{
    public:
        LinkedListi * L1 = new LinkedListi();

        void push(int value)
        {
            L1->insertathead(value);
        }

        void pop()
        {
            if(L1->head == NULL)
            {
                return;
            }
            L1->deleteathead();
        }

        int Top()
        {
            return L1->last();
        }

        bool isempty()
        {
            if(L1->head == NULL)
            {
                return true;
            }
            return false;
        }

};

int checkpre(char op)
{
    if(op == '+' || op == '-')
    {
        return 0;
    }
    else if(op == '*' || op == '/')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string prefix(string input)
{
    string convert = "";

    Stackc S;

    for(int i = input.size() - 1; i >= 0; i--)
    {
        if(input[i] >= '0' && input[i] <= '9')
        {
            convert += input[i];
        }
        else if(input[i] == '}')
        {
            S.push(input[i]);
        }
        else if(input[i] == '{')
        {
            while(!S.isempty() && S.Top() != '}')
            {
                convert += S.Top();
                S.pop();
            }
            S.pop();
        }
        else if(input[i] == ')')
        {
            S.push(input[i]);
        }
        else if(input[i] == '(')
        {
            while(!S.isempty() && S.Top() != ')')
            {
                convert += S.Top();
                S.pop();
            }
            S.pop();
        }
        else if(input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
        {
            while(!S.isempty() && (checkpre(S.Top()) >= checkpre(input[i])))
            {
                convert += S.Top();
                S.pop();
            }
            S.push(input[i]);
        }
    }

    while(!S.isempty())
    {
        convert += S.Top();
        S.pop();
    }
    
    return convert;
}

int prefixcalculation(string input)
{
    Stacki S;

    for(int i = input.length() - 1; i >= 0; i--)
    {
        if(input[i] >= '0' && input[i] <= '9')
        {
            S.push(input[i] - '0');
        }
        else
        {
            int op1 = S.Top();
            S.pop();

            int op2 = S.Top();
            S.pop();

            switch (input[i])
            {
            case '+':
                S.push(op1 + op2);
                break;
            
            case '-':
                S.push(op1 - op2);
                break;

            case '*':
                S.push(op1 * op2);
                break;

            case '/':
                S.push(op1 / op2);
                break;

            default:
                break;
            }
        }
    }

    return S.Top();
}

int main()
{
    string input = "{11+22-(3*4-7)*5}-127";
    
    string ans = prefix(input);

    reverse(ans.begin(), ans.end());
    
    cout << prefixcalculation(ans);
}