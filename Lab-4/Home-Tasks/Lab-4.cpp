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
            
            void replace(int rep, int change)
            {
                Node * n = new Node(rep);

                Node * temp = head;

                while(temp->next != NULL)
                {
                    if(temp->next->data == change)
                    {
                        n->next = temp->next->next;
                        
                        temp->next = n;
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
    T->insertattail(5);

    T->display();

    T->replace(6, 3);

    T->display();
}
