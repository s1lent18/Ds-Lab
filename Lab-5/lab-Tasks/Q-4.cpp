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

        int size = 0;

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

            temp = n;
        }

        void getsize()
        {
            Node * temp = head;

            size = 0;

            while(temp != NULL)
            {
                size += 1;
                
                temp = temp->next;
            }
        }

        void sort()
        {
            bool flag = false;

            Node * prev = NULL;
            
            Node * temp = head;

            Node * next = head->next;
            cout << "outside whike";
            while(temp->next != NULL)
            {
                cout << "wgile\n";
                if(temp->data > next->data)
                {
                    flag = true;

                    if(temp == head)
                    {
                        temp->next = next->next;

                        //next->next = temp;

                        prev = next;

                        prev->next = temp;

                        head = prev;

                        // temp = temp->next;

                        next = temp->next;
                    }
                    else
                    {
                        temp->next = next->next;

                        next->next = temp;
                        
                        
                        prev = next;

                        if(prev != NULL)
                        {
                            prev->next = next;
                        }
                        next = temp->next;

                        prev = prev->next;
                    }
                    
                }
                else
                {
                    prev = temp;
                    if(prev != NULL)
                    {
                        prev = prev->next;
                        
                    }

                    temp = temp->next;

                    next = next->next;
                
                }
            }
               
        }

        void display()
        {
            Node * temp = head;

            while(temp != NULL)
            {
                cout << "Values: " << temp->data << endl;

                temp = temp->next;
            }

            cout << endl << endl;
        }    
};

int main()
{
    LinkedList * T = new LinkedList();

    T->insertattail(2);
    T->insertattail(1);
    T->insertattail(3);
    T->insertattail(4);
    T->insertattail(0);

    T->display();

    for(int i = 0; i < 5; i++)
    {
        T->sort();
    }

    T->display();
}