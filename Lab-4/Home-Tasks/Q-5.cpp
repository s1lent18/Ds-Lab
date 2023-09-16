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

            while(temp->next != head)
            {
                temp = temp->next;
            }

            n->next = head;

            n->prev = temp;

            n->key = temp->key + 1;

            head->prev = n;

            temp->next = n;

        }

        void swap(int index1, int index2)
        {
            Node * temp = head;

            do
            {
                if(temp->key == index1)
                {
                    
                }

            }while(temp != head);
            
        }

};