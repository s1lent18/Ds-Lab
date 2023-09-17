#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node * next;
        int key;

        Node()
        {

        }

        Node(int value)
        {
            data = value;
            next = NULL;
            key = 0;
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

                n->key = 0;

                return;
            }

            Node * temp = head;

            while(temp->next != head)
            {
                temp = temp->next;
            }

            n->key = temp->key + 1;

            temp->next = n;

            n->next = head;

            temp = n;
        }

        void insertatindex(int value, int index)
        {
            Node * n = new Node(value);

            bool flag = false;

            if(head == NULL)
            {
                head = n;

                n->next = head;

                n->key = 0;

                return;
            }

            if(index == 0)
            {
                insertathead(value);

                return;
            }

            Node * temp = head;

            do
            {
                if(temp->key == index - 1)
                {
                    n->key = temp->key;

                    n->next = temp->next;

                    temp->next = n;

                    flag = true;

                    break;
                }

                temp = temp->next;

            }while(temp != head);

            if(flag)
            {
                do
                {
                    temp = temp->next;
                    
                    temp->key = temp->key + 1;
                    

                } while (temp->next != head);
            }
        }

        void insertathead(int value)
        {
            Node * n = new Node(value);

            if(head == NULL)
            {
                n->next = head;
                
                head = n;

                n->key = 0;

                return;
            }

            Node * temp = head;

            while(temp->next != head)
            {
                temp = temp->next;
            }

            temp->next = n;

            n->next = head;

            n->key = 0;

            temp = head;

            do
            {
                temp->key = temp->key + 1;

                temp = temp->next;

            }   while(temp->next != head);

            head = n;
        }

        void deleteatindex(int index)
        {
            Node * temp = head;

            bool flag = false;

            do
            {
                if(temp->key == index - 1)
                {
                    Node * del = temp;

                    temp->next = temp->next->next;

                    del = NULL;

                    delete del;

                    flag = true;

                    break;
                }
                temp = temp->next;

            }while(temp != head);

            if(flag)
            {
                do
                {
                    temp = temp->next;

                    temp->key = temp->key - 1;

                } while (temp->next != head);
            }
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

        void displaywithindex()
        {
            Node * temp = head;

            do
            {
                cout << temp->key << " --------> " << temp->data << endl;

                temp = temp->next;

            } while(temp != head);
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

    C->displaywithindex();


}