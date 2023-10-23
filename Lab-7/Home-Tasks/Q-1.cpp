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
    else if(op == '(' || op == ')')
    {
        return 2;
    }
    else if(op == '{' || op == '}')
    {
        return 3;
    }
    else
    {
        return -1;
    }
}

void prefix(string input, Stackc & forreturn)
{
    string convert = "";

    Stackc S;

    for(int i = input.size() - 1; i >= 0; i--)
    {
        if(input[i] >= '0' && input[i] <= '9')
        {
            convert += input[i];
            forreturn.push(input[i]);
        }
        else if(input[i] == '{')
        {
            while(!S.isempty() && S.Top() != '}')
            {
                convert += S.Top();
                forreturn.push(S.Top());
                S.pop();
            }
            S.pop();
        }
        else if(input[i] == '(')
        {
            while(!S.isempty() && S.Top() != ')')
            {
                convert += S.Top();
                forreturn.push(S.Top());
                S.pop();
            }
            S.pop();
        }
        else if(input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
        {
            while(!S.isempty() && (checkpre(S.Top()) >= checkpre(input[i])))
            {
                convert += S.Top();
                forreturn.push(S.Top());
                S.pop();
            }
            forreturn.push(',');
            //forreturn.push(input[i]);
            S.push(input[i]);
        }
    }

    while(!S.isempty())
    {
        convert += S.Top();
        forreturn.push(S.Top());
        S.pop();
    }
    
    reverse(convert.begin(), convert.end());

    cout << convert << endl;

    while(!forreturn.isempty())
    {
        cout << forreturn.Top();
        forreturn.pop();
    }

}

int prefixcalculation(Stackc & in)
{
    Stacki S;

    while(!in.isempty())
    {
        char check = in.Top();

        int count = 1;

        int p = 0, a = 0;

        if(check >= '0' && check <= '9')
        {
            p = check - '0';

            a += (p * count);

            count *= 10;
        }
        else if(check == ',')
        {
            S.push(a);
        } 
        else
        {
            int op1 = S.Top();
            S.pop();

            int op2 = S.Top();
            S.pop();

            switch (check)
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
        in.pop();
    }
    return S.Top();
}

int main()
{
    Stackc forreturn;

    prefix("{11+22-(3*4-7)*5}-127", forreturn);

    cout << endl << prefixcalculation(forreturn) << endl;
}