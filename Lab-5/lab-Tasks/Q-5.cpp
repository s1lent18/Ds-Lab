#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node * next;
        Node * prev;

        Node(int value)
        {
            data = value;
            next = NULL;
            prev = NULL;
        }

        Node()
        {

        };

};

class DoublyLinkedList
{
    public:
        Node * head;

        void insertattailrecursive(Node * H, int value)
        {
            Node * n = new Node(value);
            
            if(H == NULL)
            {
                H = n;
            }
            else if(H->next == NULL)
            {
                H->next = n;

                n->prev = H;
            }
            else
            {
                insertattailrecursive(H->next, value);
            }
        }

        void printrecursive(Node * H)
        {
            if(H != NULL)
            {
                cout << H->data << " -> ";

                printrecursive(H->next);
            }
        }

        void app(int data)
        {
            if(head == NULL)
            {
                Node * n = new Node(data);

                head = n;
            }
            else
            {
                insertattailrecursive(head, data);
            }
        }

        void print()
        {
            printrecursive(head);

            cout << "NULL";

            cout << endl;
        }
};

int main()
{
    DoublyLinkedList * D = new DoublyLinkedList();

    D->app(1);
    D->app(2);
    D->app(3);
    D->app(5);
    D->app(4);

    D->print();

}