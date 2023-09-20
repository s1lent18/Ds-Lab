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

        void sort()
        {
            Node * next = NULL;

            Node * temp = head;

            bool flag = false;

            while(temp != NULL)
            {
                if(temp->next == NULL)
                {
                    break;
                }
                else if(temp->data > temp->next->data)
                {
                    Node * prev = temp->next;

                    temp->next = prev->next;

                    prev->next = temp;

                    if(next == NULL)
                    {
                        head = prev;
                    }
                    else
                    {
                        next->next = prev;
                    }
                    flag = true;   
                }
                next = temp;

                temp = temp->next;
            }

            if(flag)
            {
                sort();
            }
        }

        void display()
        {
            Node * temp = head;

            cout << endl;

            while(temp != NULL)
            {
                cout << temp->data << " -> " ;

                temp = temp->next;
            }

            cout << "NULL" << endl << endl;
        }
};

int main()
{
    LinkedList * T = new LinkedList();

    T->insertattail(2);
    T->insertattail(1);
    T->insertattail(4);
    T->insertattail(3);
    T->insertattail(0);

    T->display();

    T->sort();

    T->display();
}