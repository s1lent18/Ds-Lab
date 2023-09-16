#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node * next;
        Node * prev;
        int key;

        Node()
        {

        };

        Node(int value)
        {
            data = value;
            next = NULL;
            prev = NULL;
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
                n->key = 0;
                
                head = n;

                return;
            }

            Node * temp = head;

            while(temp != NULL)
            {
                temp->key = temp->key + 1;

                temp = temp->next;   
            }
            
            head->prev = n;

            n->next = head;

            n->key = 0;

            head = n;
        }

        void insertattail(int value)
        {
            Node * n = new Node(value);

            Node * temp = head;

            if(head == NULL)
            {
                head = n;

                n->key = 0;

                return;
            }

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = n;

            n->prev = temp;

            n->key = temp->key + 1;
        }

        void insertatindex(int value, int index)
        {
            Node * n = new Node(value);

            Node * temp = head;

            bool flag = false;

            while(temp != NULL)
            {
                if(temp->key == index)
                {
                    n->prev = temp->prev;

                    n->next = temp;

                    temp->prev->next = n;

                    temp->prev = n;

                    n->key = temp->key;

                    flag = true;

                    break;
                }
                temp = temp->next;
            }

            if(flag)
            {
                do
                {
                    temp->key = temp->key + 1;
                    
                    temp = temp->next;

                } while (temp != NULL);
            }
        }

        void deleteatindex(int index)
        {
            Node * temp = head;

            bool flag = false;

            while(temp != NULL)
            {
                if(index == temp->key)
                {
                    Node * del = temp;
                    
                    del->prev->next = temp->next;

                    temp->next->prev = del->prev;

                    del = NULL;

                    delete del;

                    flag = true;

                    break;
                }
                temp = temp->next;
            }

            //temp = head->next;

            if(flag)
            {
                do
                {
                    temp->key = temp->key - 1;

                    temp = temp->next;

                } while (temp != NULL);
            }
        }

        void displayforward()
        {
            Node * temp = head;

            cout << endl;

            while(temp != NULL)
            {
                cout << temp->data << "->";

                temp = temp->next;
            }

            cout << "NULL" << endl << endl;

            temp = head;

            while(temp != NULL)
            {
                cout << temp->key << ", ";

                temp = temp->next;
            }
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

    D->deleteatindex(2);

    D->displayforward();
}