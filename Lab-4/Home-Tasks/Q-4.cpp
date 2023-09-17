#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node * next;
        Node * prev;

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

            Node * temp = head;

            if(head == NULL)
            {
                head = n;

                return;
            }

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = n;

            n->prev = temp;
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

            cout << "NULL" << endl << endl;
        }

        void join(LinkedList * L1, LinkedList * L2)
        {
            if(L1->head == NULL)
            {
                L2->head = L2->head;

                return;
            }

            Node * temp = L1->head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = L2->head;

            L2->head->prev = temp;

            L2 = NULL;

            delete L2;
        }
};

int main()
{
    LinkedList * L = new LinkedList();

    L->insertattail(1);
    L->insertattail(2);
    L->insertattail(3);
    L->insertattail(4);

    LinkedList * M = new LinkedList();

    M->insertattail(6);
    M->insertattail(7);
    M->insertattail(8);
    M->insertattail(9);

    L->join(L, M);

    L->display();
}