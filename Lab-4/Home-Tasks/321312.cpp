#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node * prev;
        Node * next;

        Node()
        {
            prev = NULL;
            next = NULL;
        }

        Node(int value)
        {
            data = value;
            prev = NULL;
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

            Node * temp = head->prev;

            n->next = head;

            head->prev = n;

            n->prev= temp;

            temp->next = n;
        }

        void display()
        {
            Node * temp = head;

            while(temp->next != head)
            {
                cout << temp->data << endl;

                temp = temp->next;
            }

            cout << temp->data << endl;

            Node * tail = head->prev;

            temp = tail;

            while(temp->prev != tail)
            {
                cout << temp->data << endl;

                temp = temp->prev;
            }

            cout << temp->data << endl;
        }
};

int main()
{
    LinkedList * T = new LinkedList();

    T->insertattail(1);
    T->insertattail(2);
    T->insertattail(3);
    T->insertattail(4);
    T->insertattail(5);

    T->display();


}