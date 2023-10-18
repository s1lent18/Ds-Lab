#include <iostream>
using namespace std;

class Node
{
    public:
        char data;
        Node * next;

        Node()
        {

        };

        Node(char value)
        {
            data = value;
            next = NULL;
        }
};

class LinkedList
{
    public:
        Node * head;

        LinkedList()
        {
            head = NULL;
        }

        void insertathead(char value)
        {
            Node * n = new Node(value);

            n->next = head;

            head = n;

            return;
        }

        void deleteathead()
        {
            Node * del = head;

            head = head->next;

            del = NULL;

            delete del;
        } 

        char last()
        {
            Node * temp = head;

            return temp->data;
        }

        void display()
        {
            Node * temp = head;

            while(temp != NULL)
            {
                cout << temp->data << " -> ";

                temp = temp->next;
            }

            cout << "NULL" << endl;
        } 
};

class Stacks
{
    private:
        LinkedList * L = new LinkedList();
        int top;

    public:
        Stacks()
        {
            top = -1;
        }

        void push(char element)
        {
            top += 1;
            
            L->insertathead(element);
        }

        void pop()
        {
            L->deleteathead();

            top -= 1;
        }

        char Top()
        {
            return L->last();
        }

        bool isempty()
        {
            if(L->head == NULL)
            {
                return 1;
            }
            return 0;
        }
};

int main()
{
    Stacks S;

    string input;

    cin >> input;

    for(int i = 0; i < input.length(); i++)
    {
        S.push(input[i]);
    }

    string check;

    for(int i = 0; i < input.length(); i++)
    {
        check += S.Top();
        S.pop();
    }

    if(check == input)
    {
        cout << "Palindrome " << endl;
    }
    else
    {
        cout << "Not Palindrome" << endl;
    }
    


}
