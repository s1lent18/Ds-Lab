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

                temp = n;
            }

            void display()
            {
                Node * temp = head;

                while(temp != NULL)
                {
                    cout << "Values: " << temp->data << endl;

                    temp = temp->next;
                }
            }

            void evenodd()
            {         	
                Node * temp = head;

                while(temp != NULL)
                {
                    if(temp->next->data % 2 == 0)
                    {
                        Node * app = temp->next;

                        temp->next = temp->next->next;                      

                        app->next = head;

                        head = app;
                        
                    }
                    temp = temp->next;
                }

            }
};

int main()
{
    LinkedList * T = new LinkedList();

    T->insertattail(1);
    T->insertattail(2);
    T->insertattail(3);
    T->insertattail(4);
    T->insertattail(6);
    T->insertattail(7);

    T->evenodd();

    T->display();
}