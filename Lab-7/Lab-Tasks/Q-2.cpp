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

        LinkedList()
        {
            head = NULL;
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

        void insertathead(int value)
        {
            Node * n = new Node(value);
            
            n->next = head;

            head = n;
        }

        int minvalue()
        {
            int min = 1000;

            Node * temp = head;

            while(temp != NULL)
            {
                if(temp->data < min)
                {
                    min = temp->data;
                }

                temp = temp->next;
            }
            return min;
        }

        void  deletebyvalue(int value)
        {
            Node * temp = head;

            if(head == NULL)
            {
                return;
            }   

            if(head->next == NULL)
            {
                deleteathead();

                return;
            }

            while(temp->next->data != value)
            {
                temp = temp->next;
            }

            Node * del = temp->next;

            temp->next = temp->next->next;

            delete del;
        }

        void deleteathead()
        {
            Node * del = head;

            head = head->next;

            del = NULL;

            delete del;
        } 

        int last()
        {
            return head->data;
        }

        void display()
        {
            Node * temp = head;

            while(temp != NULL)
            {
                cout << temp->data << " -> ";

                temp = temp->next;
            }

            cout << "NULL" << endl;
        } 
};

class Queue
{
    public:
        int size = 0;
        LinkedList * L = new LinkedList();

        void enqueue(int id)
        {
            L->insertattail(id);
            size++;
        }

        void dequeue()
        {
            L->deletebyvalue(L->minvalue());
            size--;
        }

        void debug()
        {
            cout << L->minvalue();
        }

        int top()
        {
            return L->last();
        }

        void emplace(int id)
        {
            L->insertathead(id);

            size++;
        }

        void display()
        {
            L->display();
        }
};

int main()
{
    Queue Q;

    Q.enqueue(13);
    Q.enqueue(7);
    Q.enqueue(4);
    Q.enqueue(1);
    Q.enqueue(6);
    Q.enqueue(8);
    Q.enqueue(10); 

    Q.debug(); 
    cout << endl;

    Q.display();
    Q.dequeue();
    Q.display();
}