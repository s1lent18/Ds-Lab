#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node * next;

        Node()
        {

        }

        Node(int value)
        {
            data = value;
            next = NULL;
        }
};

class CircularLinkedList
{
    public:
        Node * head;

        void insertattail(int value)
        {
            Node * n = new Node(value);

            if(head == NULL)
            {
                head = n;

                n->next = head;

                return;
            }

            Node * temp = head;

            while(temp->next != head)
            {
                temp = temp->next;
            }

            temp->next = n;

            n->next = head;

            temp = n;
        }

        void insertatindex(int value, int index)
        {
            Node * n = new Node(value);

            if(head == NULL)
            {
                head = n;

                n->next = head;

                return;
            }

            Node * temp = head;

            int count = 0;

            do
            {
                if(count == index - 1)
                {
                    n->next = temp->next;

                    temp->next = n;
                }

                temp = temp->next;

                count++;

            }while(temp != head);
        }

        void insertathead(int value)
        {
            Node * n = new Node(value);

            if(head == NULL)
            {
                n->next = head;
                
                head = n;

                return;
            }

            Node * temp = head;

            while(temp->next != head)
            {
                temp = temp->next;
            }

            temp->next = n;

            n->next = head;

            head = n;
        }

        void deleteatindex(int index)
        {
            Node * temp = head;

            int count = 0;

            do
            {
                if(count == index - 1)
                {
                    Node * del = temp;

                    temp->next = temp->next->next;

                    del = NULL;

                    delete del;
                }
                temp = temp->next;

                count++;

            }while(temp != head);
        }

        void display()
        {
            Node * temp = head;

            do
            {
                cout << "Values: " << temp->data << endl;

                temp = temp->next;

            } while (temp != head);
            
        }
};

int main()
{
    CircularLinkedList * C = new CircularLinkedList();

    C->insertattail(1);
    C->insertattail(2);
    C->insertattail(3);
    //C->insertattail(4);
    C->insertattail(5);
    C->insertathead(0);

    C->insertatindex(4, 4);

    C->deleteatindex(2);

    C->display();


}