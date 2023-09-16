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

class DoublyLinkedList
{
    public:
        Node * head;

        void insertathead(int value)
        {
            Node * n = new Node(value);

            if(head == NULL)
            {
                n->prev = n;
                
                n->next = n;
                
                head = n;

                return;
            }

            Node * end = head->prev;

            n->next = head;

            n->prev = end;

            head->prev = n;

            end->next = n;

            head = n;
        }

        void insertattail(int value)
        {
            Node * n = new Node(value);

            if(head == NULL)
            {
                n->next = n;

                n->prev = n;

                head = n;
                
                return;
            }

            Node * end = head->prev;

            n->next = head;

            n->prev = end;

            head->prev = n;

            end->next = n;
        }

        void display()
        {
            Node * temp = head;

            cout << endl;

            do
            {
                cout << temp->data << "->";

                temp = temp->next;

            }while(temp != head);

            cout << temp->data << endl << endl;

        }
};

int main()
{
    DoublyLinkedList * D = new DoublyLinkedList();

    D->insertattail(1);
    D->insertattail(1);
    D->insertattail(1);
    D->insertattail(1);
    D->insertattail(1);
    
    D->insertathead(0);

    D->display();

}