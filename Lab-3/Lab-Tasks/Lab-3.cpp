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

            tail = n;
        }

        void insertattailwithO_1complexity(int value)
        {
            Node * n = new Node(value);

            if(head == NULL)
            {
                head = n;
                tail = n;

                return;
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
                Node * del = head;

                head = head->link;

                delete del;
            }

            while(temp->link->link != NULL)
            {
                temp = temp->link;
            }

            tail = temp;

            delete temp->link;

            temp->link = NULL;
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

                return;
            }

            while(temp->link->data != value)
            {
                temp = temp->link;
            }

            tail = temp;

            Node * del = temp->link;

            temp->link = temp->link->link;

            delete del;
        }

        void deletebyindex(int index)
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

                return;
            }

            int count = 0;

            while(temp && count < index - 1)
            {
                count++;

                temp = temp->link;
            }

            Node * del = temp->link;

            temp->link = del->link;

            delete del;
        }

        void insertaftervalue(int value, int valueafter)
        {
            Node * n = new Node(value);

            Node * temp = head;

            while(temp->link != NULL)
            {
                if(temp->data == valueafter)
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

            while(temp != NULL)
            {
                cout << "Values: " << temp->data << endl;

                temp = temp->link;
            }
            cout << endl;
        }
};

int main()
{
    LinkedList * head = new LinkedList();
    Node * temp;

// Q1[a]:
    cout << "Insert at tail: " << endl;

    head->insertattail(5);
    head->insertattail(6);
    head->insertattail(8);
    head->insertattail(9);
    head->display();

//Q1[a] part-2:
    cout << "Insert at tail with O(1) complexity: " << endl;

    head->insertattailwithO_1complexity(10);

    head->display();

// Q1[b]:
    cout << "Insert at head: " << endl;

    head->insertathead(4);
    head->insertathead(3);
    head->insertathead(2);
    head->insertathead(1);
    head->insertathead(0);
    head->display();

// Q2:
    cout << "Insert after value: " << endl;

    head->insertaftervalue(7, 6);
    head->display();

// Q3[delete last node]:
    cout << "delete last node: " << endl;

    head->deleteattail();
    head->display();

// Q3[delete by value]:
    cout << "Delete after value: " << endl;

    head->deletebyvalue(5);
    head->display();

// Q3[delete by index]:
    cout << "Delete at index: " << endl;

    head->deletebyindex(3);
    head->display();
}