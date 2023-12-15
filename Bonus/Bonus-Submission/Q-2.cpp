#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Stack
{
    private:
        int * arr;
        int top;
        int size;

    public:
        Stack(int size)
        {
            this->size = size;
            arr = new int[size];
            top = -1;
        }

        void push(int element)
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

        int Top()
        {
            if(top == - 1)
            {
                cout << "Stack Empty no element to pop " << endl;

                return -1;
            }

            return arr[top];
        }

        bool empty()
        {
            return top == -1;
        }

        void print()
        {
            for(int i = 0; i < size; i++)
            {
                cout << Top() << endl;

                pop();
            }
        }
};

class Node
{
    public:
        int dec;
        Node * next;

        Node()
        {
            next = NULL;
        }

        Node(int deci)
        {
            this->dec = deci;

            next = NULL;
        }
};

class LinkedList
{
    public:
        Node * head;

        void append(int val)
        {
            Node * n = new Node(val);

            if(head == NULL)
            {
                head = n;

                return;
            }

            Node * temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = n;
        }

        void display()
        {
            Node * temp = head;

            while(temp != NULL)
            {
                cout << temp->dec << " ";

                temp = temp->next;
            }
        }

        void sort()
        {
            Node * next = NULL;

            Node * temp = head;

            bool flag = false;

            while(temp != NULL)
            {
                if(temp->next == NULL)
                {
                    break;
                }
                else if(temp->dec > temp->next->dec)
                {
                    Node * prev = temp->next;

                    temp->next = prev->next;

                    prev->next = temp;

                    if(next == NULL)
                    {
                        head = prev;
                    }
                    else
                    {
                        next->next = prev;
                    }
                    flag = true;
                }
                next = temp;

                temp = temp->next;
            }
            if(flag)
            {
                sort();
            }
        }

        void Q2()
        {
            Node * temp = head;

            int i = 1;

            while(temp != NULL)
            {
                int sec = temp->dec % 10;

                temp->dec -= sec;

                temp->dec /= 10;

                int first = temp->dec;

                int temp1 = first;
                int temp2 = sec;

                Stack F(10);
                Stack S(10);

                while(temp1 > 0)
                {
                    F.push(temp1 % 2);

                    temp1 /= 2;
                }

                while(temp2 > 0)
                {
                    S.push(temp2 % 2);

                    temp2 /= 2;
                }

                string f;
                string s;

                while(!F.empty())
                {
                    f += to_string(F.Top());

                    F.pop();
                }

                while(!S.empty())
                {
                    s += to_string(S.Top());

                    S.pop();
                }

                if(i % 2 != 0)
                {
                    if(first == sec)
                    {
                        string ft, st;
                        
                        for(int k = 1; k < f.length(); k++)
                        {
                            ft += f[k];
                        }

                        ft += "0";

                        st += "0";

                        for(int k = 0; k < s.length() - 1; k++)
                        {
                           st += s[k];
                        }
                        
                        f = ft;
                        s = st;
                        
                        for(int k = 0; k < f.length(); k++)
                        {
                            if(f[k] == '1' && s[k] == '1')
                            {
                                f[k] = '1';
                            }
                            else
                            {
                                f[k] = '0';
                            }
                        }
                        
                        int change = stoi(f);

                        int j = 0,  remainder = 0;
                        
                        temp->dec = 0;

                        while(change != 0)
                        {
                            remainder = change % 10;
                            change /= 10;
                            temp->dec += remainder * pow(2, j);
                            j++;
                        }
                    }
                    else
                    {
                        string ft, st;
                        
                        for(int k = 1; k < f.length(); k++)
                        {
                            ft += f[k];
                        }

                        ft += f[f.length() - 1];

                        st += s[s.length() - 1];

                        for(int k = 1; k < s.length(); k++)
                        {
                           st += s[k];
                        }
                        
                        f = ft;
                        s = st;
                        
                        for(int k = 0; k < f.length(); k++)
                        {
                            if(f[k] == '1' && s[k] == '1')
                            {
                                f[k] = '1';
                            }
                            else
                            {
                                f[k] = '0';
                            }
                        }
                        
                        int change = stoi(f);

                        int j = 0,  remainder = 0;
                        
                        temp->dec = 0;

                        while(change != 0)
                        {
                            remainder = change % 10;
                            change /= 10;
                            temp->dec += remainder * pow(2, j);
                            j++;
                        }
                    }
                }
                else
                {
                    if(first == sec)
                    {
                        string ft, st;
                        
                        for(int k = 1; k < f.length(); k++)
                        {
                            ft += f[k];
                        }

                        ft += "0";

                        st += "0";

                        for(int k = 0; k < s.length() - 1; k++)
                        {
                           st += s[k];
                        }
                        
                        f = ft;
                        s = st;
                        
                        for(int k = 0; k < f.length(); k++)
                        {
                            if(f[k] == '1' || s[k] == '1')
                            {
                                f[k] = '1';
                            }
                            else
                            {
                                f[k] = '0';
                            }
                        }
                        
                        int change = stoi(f);
                        
                        int j = 0,  remainder = 0;
                        
                        temp->dec = 0;

                        while(change != 0)
                        {
                            remainder = change % 10;
                            change /= 10;
                            temp->dec += remainder * pow(2, j);
                            j++;
                        }
                    }
                    else
                    {
                        string ft, st;
                        
                        for(int k = 1; k < f.length(); k++)
                        {
                            ft += f[k];
                        }

                        ft += f[f.length() - 1];

                        st += s[s.length() - 1];

                        for(int k = 1; k < s.length(); k++)
                        {
                           st += s[k];
                        }
                        
                        f = ft;
                        s = st;
                        
                        for(int k = 0; k < f.length(); k++)
                        {
                            if(f[k] == '1' || s[k] == '1')
                            {
                                f[k] = '1';
                            }
                            else
                            {
                                f[k] = '0';
                            }
                        }
                        
                        int change = stoi(f);

                        int j = 0,  remainder = 0;
                        
                        temp->dec = 0;

                        while(change != 0)
                        {
                            remainder = change % 10;
                            change /= 10;
                            temp->dec += remainder * pow(2, j);
                            j++;
                        }
                    }
                }

                temp = temp->next;
                i++;
            }
        }
};

int main()
{
    LinkedList * L = new LinkedList();

    L->append(99);

    L->append(88);

    L->append(76);

    L->append(45);

    L->display();

    L->Q2();

    L->sort();
        
    L->display();
}