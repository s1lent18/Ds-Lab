#include <iostream>
using namespace std;

class Node
{
    public:
        int taskid;
        int storage;
        int time;
        int memory;
        Node * next;

        Node()
        {
            next = NULL;
        }

        Node(int taskid, int storage, int time, int memory)
        {
            this->taskid = taskid;
            this->storage = storage;
            this->time = time;
            this->memory = memory;
        }

};

class LinkedList
{
    public:
        Node * head;

        void insertattail(int taskid, int storage, int time, int memory)
        {
            Node * n = new Node(taskid, storage, time, memory);

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

        Node * Top()
        {
            return head;
        }

        Node * deleteathead()
        {
            Node * del = head;

            head = head->next;

            del->next = NULL;

            return del;
        }


};

class Queue
{
    public:
        LinkedList * arr = new LinkedList();

        void push(int taskid, int storage, int time, int memory)
        {
            arr->insertattail(taskid, storage, time, memory);
        }   

        Node * pop()
        {
            return arr->deleteathead();
        }

        Node * peek()
        {
            return arr->Top();
        }    

        Node * minmemory()
        {
            Node * temp = arr->head;

            Node * ret = new Node();

            int min = 1024;
            int id = 0;

            while(temp != NULL)
            {
                if(min > temp->memory)
                {
                    min = temp->memory;
                    ret = temp;
                }
                temp = temp->next;
            }

            return ret;
        }

        void deletenode(Node * n)
        {
            Node * temp = arr->head;

            while(temp != NULL)
            {
                if(n->taskid == temp->next->taskid)
                {
                    Node * del = temp->next;

                    temp->next = temp->next->next;

                    del = NULL;

                    delete del;
                }

                temp = temp->next;
            }
        }

        bool isempty()
        {
            return arr->head == NULL;
        }
        
};

void Q2()
{
    Queue Q1;
    Queue Q2;

    Q1.push(1, 2, 20, 512);
    Q1.push(2, 1, 15, 256);
    Q1.push(3, 3, 25, 768);
    Q1.push(4, 2, 18, 384);

    int size = 1024;

    while(!Q1.isempty() && !Q2.isempty())
    {
        Node * p = Q1.minmemory();

        int taskid = p->taskid;
        int storage = p->storage;
        int time = p->time;
        int memory = p->memory;

        if(size > p->memory)
        {
            size -= p->memory;

            Q2.push(taskid, storage, time, memory);
        }
        else
        {
            Node * check = Q2.pop();

            taskid = check->taskid;
            storage = check->storage;
            time = check->time;
            memory = check->memory;

            Q1.push(taskid, storage, time, memory);
        }
        
        Q1.deletenode(p);

        if(Q1.isempty())
        {
            while(!Q2.isempty())
            {
                Q2.pop();
            }
        }
    }

}

int main()
{
    Q2();

    return 0;
}