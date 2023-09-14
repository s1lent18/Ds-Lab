#include <iostream>
using namespace std;

class Node
{
    public:
        string data;
        Node * prev;
        Node * next;

        Node()
        {

        };

        Node(string value)
        {
            data = value;
            next = NULL;
            prev - NULL;
        }

};

class LinkedList
{
    public:
        Node * head;
        string one;
        string two;
        
        void insertattail(string value)
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

            n->prev = temp;

            temp = n;
        }

        void front()
        {
            Node * temp = head;

            while(temp->next != NULL)
            {
                one += temp->data;

                temp = temp->next;
            }

            one += temp->data;

            //cout << one;

            while(temp != head)
            {
                two += temp->data;

                temp = temp->prev;
            }

            two += temp->data;

             if(one == two)
            {
                cout << "Palindrome";
            }
            else
            {
                cout << "Not Palindrome";
            }
        }

       
};

int main()
{
    LinkedList * T = new LinkedList();

    T->insertattail("A");
    T->insertattail("B");
    T->insertattail("C");
    T->insertattail("B");
    T->insertattail("B");

    T->front();
}
