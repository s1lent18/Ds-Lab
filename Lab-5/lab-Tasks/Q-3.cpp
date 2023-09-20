#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node * next;

        Node()
        {

        };

        Node(int value)
        {
            data = value;
            next = NULL;
        }
};

class LinkedList
{
    public:
        Node * head;

        void insertattail(int value)
        {
            Node * n = new Node(value);

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
                cout << temp->data << " -> ";

                temp = temp->next;
            }

        }

        void printwithrecursion(Node * T)
        {
            if(T == NULL)
            {
                return;
            }
            else
            {
                printwithrecursion(T->next);
            }
            cout << T->data << " -> ";
        }

        void print()
        {   
            printwithrecursion(head);

            cout << "NULL";
        }
};

int main()
{
    LinkedList * L = new LinkedList();

    L->insertattail(1);
    L->insertattail(2);
    L->insertattail(3);
    L->insertattail(4);
    L->insertattail(5);

    L->print();
}