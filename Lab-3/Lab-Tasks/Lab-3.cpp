#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node * link;
        
        Node()
        {

        };

        Node(int value)
        {
            this->data = value;
            link = NULL;
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

                return;
            }

            Node * temp = head;
            
            while(temp->link != NULL)
            {
                temp = temp->link;
            }

            temp->link = n;
        }

        Node * gettail()
        {
            return tail;
        }

        void insertattailforO_1complexity(int value)
        {
            Node * n = new Node(value);

            if(head == NULL)
            {
                head = n;
                tail = n;
            }

            tail->link = n;
            tail = n;
        }

        void insertathead(int value)
        {
            Node * n = new Node(value);

            n->link = head;

            head = n;    
        }

        void deleteattail()
        {
            Node * temp = head;

            if(head == NULL)
            {
                return;
            }

            if(head->link == NULL)
            {
                Node * del;

                head = head->link;

                delete del;
            }

            while(temp->link->link != NULL)
            {
                temp = temp->link;
            }

            temp->link = NULL;
        }

        void deletebyindex(int index)
        {
            if(head  == NULL || index < 0)
            {
                return;
            }

            if(index == 0)
            {
                Node * n = head;

                head = head->link;

                delete n;
            }

            Node * temp = head;

            int count = 0;

            while(count < index - 1)
            {
                temp = temp->link;
                
                count++;
            }

            Node * del = temp->link;

            temp->link = del->link;

            delete del;
        }

        void deletebyvalue(int value)
        {
            Node * temp = head;

            if(head == NULL)
            {
                return;
            }

            if(head->link == NULL)
            {
                Node * del = head;

                head = head->link;

                delete del;
            }

            while(temp->link->data != value)
            {
                temp = temp->link;
            }

            Node * del = temp->link;

            temp->link = temp->link->link;

            delete del;
        }

        void insertaftervalue(int insert, int check)
        {
            Node * n = new Node(insert);

            Node * temp = head;

            while(temp->link != NULL)
            {
                if(temp->data == check)
                {
                    n->link = temp->link;

                    temp->link = n;
                }

                temp = temp->link;
            }
        }

        void display()
        {
            Node * temp = head;

            int count = 0;

            while(temp != NULL)
            {
                cout << "Value: " << temp->data << endl;

                temp = temp->link;
            }
            cout << endl << endl;
        }


};

int main()
{
    LinkedList * head = new LinkedList();
    Node * temp;

// Q1[a]:
    head->insertattail(1);
    head->insertattail(2);
    head->insertattail(3);
    head->insertattail(4);
    head->insertattail(5);
    head->display();

// Q1[a] part-2:
    // head->insertattailforO_1complexity(5);

    // temp = head->gettail();

    // cout << "Last Node in the linked list: " << temp->data << endl;

// Q1[b]:  
    head->insertathead(0);
    head->insertathead(-1);
    head->insertathead(-2);
    head->insertathead(-3);
    head->insertathead(-4);
    head->display();

// Q2:
    head->insertaftervalue(-2, -3);
    head->display();

// Q3[delete last node]:
    head->deleteattail();
    head->display();

// Q3[delete by value]:
    head->deletebyvalue(-2);
    head->display();

// Q3[delete by index]:
    head->deletebyindex(5);
    head->display();
    
}