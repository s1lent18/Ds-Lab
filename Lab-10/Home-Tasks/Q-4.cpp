#include <iostream>
using namespace std;

class Node
{
    public:
        Tasks data;
        Node * next;

        Node()
        {

        };

        Node(Tasks data)
        {
            this->data = data;
            next = NULL;
        }
};

class LinkedList
{
    public:
        Node * head;

        void append(Tasks data)
        {
            Node * n = new Node(data);

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

        void deleteathead()
        {
            Node * temp = head;

            head = head->next;

            temp = NULL;

            delete temp;
        }

        Tasks last()
        {
            return head->data;
        }
};

class Queue
{
    public:
        LinkedList * L;

        void enqueue(Tasks data)
        {
            L->append(data);
        }

        void dequeue()
        {
            L->deleteathead();
        }

        Tasks Top()
        {
            return L->last();
        }

        bool isempty()
        {
            return L->head == NULL;
        }
};

class Tasks
{
    public:
        int memory;
        int exetime;

        Tasks()
        {

        };

        Tasks(int memory, int exetime)
        {
            this->memory = memory;
            this->exetime = exetime;
        }

        int returnprio()
        {
            return memory * exetime;
        }
};

Queue priority(Tasks * arr, int size)
{
    Queue Q;

    Tasks A;

    int max = 100000;
    int last = 0;

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if((arr[j].returnprio() < max) && arr[j].returnprio() > last)
            {
                A = arr[j];
            }
        }
        Q.enqueue(A);
    }
}

int main()
{
    int size = 0;

    cout << "Enter the size for your array: ";

    cin >> size;

    Tasks * T = new Tasks();

    for(int i = 0; i < size; i++)
    {
        cin >> T[i].memory;
        cin >> T[i].exetime;
    }

    Queue ans = priority(T, size);
}