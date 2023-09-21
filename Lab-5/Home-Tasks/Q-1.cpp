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

        void evenodd()
        {
            Node * temp = head->next;

            Node * prev = head;

            bool flag = false;

            while(temp != NULL)
            {
                cout << "While";

                if(temp->data % 2 != 0)
                {
                    flag = true;

                    cout << "true";

                    if(prev == head)
                    {
                        cout << "Hi";
                        prev->next = tail->next;

                        tail->next = prev;

                        head = temp;

                        prev = temp;

                        temp = temp->next;

                        display();
                    }   
                    // else
                    // {
                    //     temp->next = tail->next;
                        
                    //     tail->next = temp;

                    //     prev->next = temp->next;

                    //     prev = prev->next->next;
                    // }
                }
                // else
                // {
                //     temp = temp->next;

                //     prev = prev->next;
                // }
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

            cout << " NULL" << endl << endl;
        }
};

int main()
{
    LinkedList * L = new LinkedList();

    L->insertattail(1);
    L->insertattail(2);
    L->insertattail(3);
    L->insertattail(4);
    L->insertattail(5);
    L->insertattail(6);

    L->evenodd();

    L->display();
}