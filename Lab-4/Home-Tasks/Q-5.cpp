#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node * prev;
        Node * next;
        int key;

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

        void insertattail(int value)
        {
            Node * n = new Node(value);

            if(head == NULL)
            {
                n->next = n;

                n->prev = n;

                n->key = 0;

                head = n;
                
                return;
            }

            Node * end = head->prev;

            Node * temp = head;

            while(temp->next != head)
            {
                temp = temp->next;
            }

            n->next = head;

            n->prev = temp;

            n->key = temp->key + 1;

            head->prev = n;

            temp->next = n;

        }

        void swap(int index1, int index2)
        {
            Node * temp = head;

            Node * t1;
            Node * t2;
            Node * t1p;
            Node * t1n;
            Node * t2p;
            Node * t2n;

            do
            {
                if(temp->key == index1)
                {
                    t1 = temp;

                    t1p = temp->prev;

                    t1n = temp->next;
                }

                temp = temp->next;

            }while(temp != head);

            temp = head;
            
            do
            {
                if(temp->key == index2)
                {
                    t2 = temp;

                    t2p = temp->prev;

                    t2n = temp->next;
                }

                temp = temp->next;

            }while(temp != head);

            t1->prev->next = t2;

            t2->prev->next = t1;

            t1->next->prev = t2;

            t2->next->prev = t1;

            t1->prev = t2p;

            t1->next = t2n;

            t2->prev = t1p;

            t2->next = t1n;
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

        }

};

int main()
{
    DoublyLinkedList * D = new DoublyLinkedList();

    D->insertattail(1);
    D->insertattail(7);
    D->insertattail(4);
    D->insertattail(2);
    D->insertattail(6);
    D->insertattail(4);
    D->insertattail(5);
    D->insertattail(3);
    D->insertattail(9);
    D->insertattail(8);

    D->display();

    D->swap(3, 7);

    D->display();
}