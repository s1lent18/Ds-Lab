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

        void deleteathead()
        {
            Node * del = head;

            head = head->next;

            del = NULL;

            delete del;
        }


};

int main()
{
    return 0;
}