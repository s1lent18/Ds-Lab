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

        };

        Node(int value)
        {
            data = value;
            prev = NULL;
            next = NULL;
        }
};

class LinkedList
{
    public:
        Node * head;

        void insertattail(int value)
        {
            Node * n = new Node(value);

            if(head == NULL)
            {
                n->next = n;
                
                n->prev = n;

                head = n;

                n->key = 1;

                return;
            }

            Node * temp = head->prev;

            n->key = temp->key + 1;

            temp->next = n;

            n->prev = temp;

            n->next = head;

            head->prev = n;
        }

        void insertafterindex(int index, int value)
        {
            Node * n = new Node(value);

            if(head == NULL)
            {
                n->next = n;

                n->prev = n;

                head = n;

                return;
            }

            Node * temp = head;

            do
            {
                if(temp->key == index)
                {
                    n->prev = temp;

                    n->next = temp->next;

                    temp->next->prev = n;

                    temp->next = n;

                    return;
                }
                temp = temp->next;

            }while(temp != head);

            n->prev = temp->prev;

            n->next = temp;

            temp->prev->next = n;

            temp->prev = n;

        }

        void display()
        {
            Node * temp = head;

            do
            {
                cout << temp->data << "->";

                temp = temp->next;

            } while (temp != head);
            
            cout<< "NULL" << endl;
        }

        void deleteattail()
        {
            if(head == NULL)
            {
                return;
            }

            if(head->next == NULL)
            {
                head = NULL;

                delete head;
                
                return;
            }

            Node * temp = head->prev;

            temp->prev->next = head;

            head->prev = temp->prev;

            temp = NULL;

            delete temp;
        }

        void deleteatindex(int index)
        {
            if(index == 0)
            {
                Node * del = head;

                Node * temp = head;

                while(temp->next != head)
                {
                    temp = temp->next;
                }

                temp->next = head->next;

                head->next->prev = temp;

                head = head->next;

                del = NULL;

                delete del;

                return;
            }

            Node * temp = head;

            do
            {
                if(temp->key == index)
                {
                    Node * del = temp->next;

                    temp->next = del->next;

                    del->next->prev = temp;

                    del = NULL;

                    delete del;

                    return;
                }
                temp = temp->next;

            }while(temp != head);
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

    //T->insertafterindex(3, 22);

    T->deleteatindex(0);

    //T->deleteattail();

    T->display();
}