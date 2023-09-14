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

        int size = 0;

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

            temp = n;
        }

        void getsize()
        {
            Node * temp = head;

            size = 0;

            while(temp != NULL)
            {
                size += 1;
                
                temp = temp->next;
            }
        }

        Node * swap(Node * a1, Node * a2)
        {
            Node * temp = a2->next;

            a2->next = a1->next;

            a1->next = temp;

            return a2;
        }

        void sorting()
        {
            if (head == NULL)
            {
                return;
            }

            if(head->next == NULL)
            {
                return;
            }

            bool swapped;
            
            Node * end = NULL;

            do
            {
                swapped = false;

                Node * temp = head;

                while (temp->next != end)
                {
                    if (temp->data > temp->next->data)
                    {
                        int tempforint = temp->data;

                        temp->data = temp->next->data;

                        temp->next->data = tempforint;

                        swapped = true;
                    }

                    temp = temp->next;
                }

                end = temp;

            } while(swapped);
        } 

        void display()
        {
            Node * temp = head;

            while(temp != NULL)
            {
                cout << "Values: " << temp->data << endl;

                temp = temp->next;
            }

            cout << endl << endl;
        }    
};

int main()
{
    LinkedList * T = new LinkedList();

    T->insertattail(1);
    T->insertattail(10);
    T->insertattail(2);
    T->insertattail(0);
    T->insertattail(9);

    T->display();

    T->sorting();

    T->display();
}