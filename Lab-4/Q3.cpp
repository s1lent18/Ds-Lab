#include <iostream>
using namespace std;

class Node
{
    public:
        string data;
        Node * prev;
        Node * next;
        int key;

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

                n->key = 1;

                return;
            }

            Node * temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = n;

            n->prev = temp;

            n->key = temp->key + 1;

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

            while(temp != head)
            {
                two += temp->data;

                temp = temp->prev;
            }

            two += temp->data;

            if(one == two)
            {
                cout << "Palindrome" << endl;
            }
            else
            {
                cout << "Not Palindrome" << endl;
            }
        }

       
};

int main()
{
    LinkedList * T = new LinkedList();

    T->insertattail("1");
    T->insertattail("0");
    T->insertattail("2");
    T->insertattail("0");
    T->insertattail("1");

    T->front();
}