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

        void insertattail(Node * & head, int value)
        {
            Node * n = new Node(value);

            if(head == NULL)
            {
                head = n;
                //tail = n;
                return;
            }

            Node * temp = head;

            while(temp->link != NULL)
            {
                temp = temp->link;
            }

            temp->link = n;
        }

        // Since my linked list is by reference therefore the logic of the below function is correct by the 
        // code will give runtime error because the Node tail defined in Linked-List class cannot be passed by
        // reference in main function

        void insertattailwithO_1Complexity(int value)
        {
            Node * n = new Node(value);

            if(head == NULL)
            {
                head = n;
                tail = n;

            } else
            {
                tail->link = n;
                tail = n;
            }
        }

        void insertathead(Node * & head, int value)
        {
            Node *n = new Node(value);
            
            n->link = head;

            head = n;
        }

        void deleteattail(Node * & head)
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

            temp->link = NULL;
        }

        void deletebyvalue(Node * & head, int value)
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

        void deleteatindex(Node * & head, int index)
        {
            int count = 0;

            Node * temp = head;

            if(head == NULL)       // if the head is empty
            {
                return;
            }

            if(head->link == NULL) // if head has only 1 value
            {
                Node * del = head;

                head = head->link;

                delete del;
            }

            while(temp->link != NULL)
            {
                if(index - 1 == count)
                {
                    Node * del = temp->link;

                    temp->link = temp->link->link;

                    delete del;

                } 
                count++;
                temp = temp->link;

            }

        }

        void insertaftervalue(Node * & head, int value, int check)
        {
            Node * n = new Node(value);

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

        void display(Node * head)
        {
            Node * temp = head;

            while(temp != NULL)
            {
                cout << "Value: " << temp->data << endl;

                temp = temp->link;
            }
            cout << endl;
        }

};

int main()
{
    Node * temp = NULL;
    Node * last = NULL;
    LinkedList *Head;

    Head->insertattail(temp, 10);
    Head->insertattail(temp, 20);
    Head->insertattail(temp, 30);
    Head->insertattail(temp, 40);
    Head->insertattail(temp, 50);

    cout << "Values after inserting at tail: " << endl;

    Head->display(temp);

    Head->insertathead(temp, 4);
    Head->insertathead(temp, 3);
    Head->insertathead(temp, 2);
    Head->insertathead(temp, 1);

    cout << "Values after inserting at head: " << endl;

    Head->display(temp);

    Head->insertaftervalue(temp, 35, 30);

    Head->display(temp);

    //Head->insertattailwithO_1Complexity(temp, 9);

    Head->deletebyvalue(temp, 35);

    Head->deleteatindex(temp, 3);

    Head->display(temp);
}