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

        void solve()
        {
            Node * last;

            Node * temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            last = temp;

            Node * change = head->next;

            Node * t = head;

            while(change != NULL && change->next != NULL)
            {
                last->next = change;

                last = change;

                t->next = t->next->next;

                change = change->next->next;
            }
             
        }

        void display()
        {
            Node * temp = head;

            cout << endl;

            while(temp != NULL)
            {
                cout << temp->data << "->";

                temp = temp->next;
            }

            cout << endl << endl;
        }
};

int main()
{
    LinkedList * L = new LinkedList();

    L->insertattail(10);
    L->insertattail(4);
    L->insertattail(9);
    L->insertattail(1);
    L->insertattail(3);
    L->insertattail(5);
    L->insertattail(9);
    L->insertattail(4);

    L->display();

    L->solve();

    L->display();
}