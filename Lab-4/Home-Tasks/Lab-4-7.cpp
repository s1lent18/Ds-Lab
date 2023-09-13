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
            int size = 0;

            int getsize()
            {
                Node * temp = head;

                int count = 0;

                while(temp != NULL)
                {
                    count++;

                    temp = temp->next;

                }

                size = count;

                return size;                         
            }

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

            Node * swap(Node * ptr1, Node * ptr2)
            {               
                Node * temp = ptr2->next;

                ptr2->next = ptr1->next;

                ptr1->next = temp;

                return ptr2;
            }

            void bubblesort()
            {
                getsize();

                for(int i = 1; i <= getsize(); i++)
                {
                    Node * temp = head;

                    int swapped = 0;

                    Node * ptr1 = temp;

                    Node * ptr2 = ptr1->next;

                    for(int j = 0; j < getsize() - i; j++)
                    {
                        if(ptr1->data > ptr2->data)
                        {
                            temp = swap(ptr1, ptr2);

                            swapped = 1;
                        }
                        temp = temp->next;
                    }

                    if(swapped == 0)
                    {
                        break;
                    }
                }
            }
};

int main()
{
    LinkedList * T = new LinkedList();

    T->insertattail(1);
    T->insertattail(5);
    T->insertattail(4);
    T->insertattail(2);
    T->insertattail(10);

    T->bubblesort();

    T->display();
}


