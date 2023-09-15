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

        void sort()
        {
            Node * prev = NULL;
            
            Node * temp = head;

            Node * next = head->next;

            while(temp->next != NULL)
            {
                if(temp->data > next->data)
                {
                    temp->next = next->next;

                    next->next = temp;

                    prev->next = next;

                    prev = next;

                    next = temp->next;
                }
                else
                {
                    prev = head;

                    temp = temp->next;

                    next = next->next;
                
                }
            }

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

    T->sort();

    T->display();
}