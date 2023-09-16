#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node * prev;
        Node * next;
        int key;

        Node()
        {
            prev = NULL;
            next = NULL;
        }

        Node(int value)
        {
            data = value;
            prev = NULL;
            next = NULL;
        }

};

class DoublyLinkedList
{
    public:
        Node * head;

        void insertathead(int value)
        {
            Node * n = new Node(value);

            if(head == NULL)
            {
                n->prev = n;
                
                n->next = n;

                n->key = 0;
                
                head = n;

                return;
            }

            Node * end = head->prev;

            Node * temp = head->next;

            n->next = head;

            n->prev = end;

            n->key = 0;

            head->prev = n;

            end->next = n;

            do
            {
                temp->key = temp->key + 1;

                temp = temp->next;

            }   while(temp->next != head);

            head = n;
        }

        void insertattail(int value)
        {
            Node * n = new Node(value);

            if(head == NULL)
            {
                n->next = n;

                n->prev = n;

                n->key = 0;

                head = n;
                
                return;
            }

            Node * end = head->prev;

            Node * temp = head;

            do
            {
                temp = temp->next;

            }while(temp->next != head);

            n->next = head;

            n->prev = temp;

            n->key = temp->key + 1;

            head->prev = n;

            temp->next = n;

        }

        void insertatindex(int value, int index)
        {
            Node * n = new Node(value);
            
            Node * temp = head;

            if(head == NULL)
            {
                n->next = n;

                n->prev = n;

                head = n;

                return;
            }

            if(index == 0)
            {
                insertathead(value);

                return;
            }

            int count = 0;

            bool flag = false;

            do
            {
                if(count == index)
                {
                    n->key = temp->prev->key + 1;
                    
                    n->prev = temp->prev;
                    
                    n->next = temp;
                    
                    temp->prev->next = n;
                    
                    temp->prev = n;

                    flag = true;
                }

                temp = temp->next;

                count++;

            }while(temp != head);

            if(flag)
            {
                do
                {
                    temp = temp->next;

                    temp->key = temp->prev->key + 1;

                } while (temp->next != head);
            }
            
        }

        void deleteatindex(int index)
        {

        }

        void display()
        {
            Node * temp = head;

            cout << endl;

            do
            {
                cout << temp->data << "->";

                temp = temp->next;

            }while(temp != head);

            cout << temp->data << endl << endl;

            temp = head;

            do
            {
                cout << temp->key << "->";

                temp = temp->next;

            }while(temp != head);

        }
};

int main()
{
    DoublyLinkedList * D = new DoublyLinkedList();

    D->insertattail(1);
    D->insertattail(2);
    D->insertattail(3);
    D->insertattail(5);
    D->insertattail(6);
    
    D->insertathead(0);

    D->insertatindex(4, 4);

    D->display();

}