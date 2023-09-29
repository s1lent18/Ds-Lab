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

        Node(int data)
        {
            this->data = data;
            next = NULL;
        }

};

class LinkedList
{
    public:
        Node * head;
        Node * tail;

        LinkedList()
        {
            head = NULL;
            tail = NULL;
        }

        void insertattail(int value)
        {
            Node * n = new Node(value);

            if(head == NULL)
            {
                head = n;

                tail = n;

                return;
            }

            Node * temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = n;
            
            tail = n;
        }

        void evenodd(Node *& temp, Node *& prev, int firstodd, int count)
        {
            //int firstodd = 0, count = 0;

            if(firstodd == temp->data)
            {
                return;
            }

            if(temp->data % 2 != 0)
            {
                if(count == 0)
                {
                    firstodd = temp->data;
                }

                count++;

                insertattail(temp->data);

                if(temp == head)
                {
                    head = temp->next;
                    
                    temp = NULL;

                    temp = head;

                }
                else
                {
                    prev->next = temp->next;

                    temp = NULL;

                    temp = prev->next;
                }
                display();
            }
            else
            {
                prev = temp;

                temp = temp->next;
            }
            
            evenodd(temp, prev, firstodd, count);
        }

        void change()
        {
            Node * temp = head;

            Node * prev = NULL;

            evenodd(temp, prev, 0, 0);
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
    LinkedList * L = new LinkedList();

    L->insertattail(1);
    L->insertattail(2);
    L->insertattail(4);
    L->insertattail(3);
    L->insertattail(5);
    L->insertattail(6);

    L->display();

    L->change();

    L->display();
}