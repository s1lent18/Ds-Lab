#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Node
{
    public:
        int weight;
        char name;
        const int size = 26;
        Node * next;

        Node()
        {
            next = NULL;
        };

        Node(char name, int weight)
        {
            this->name = name;
            this->weight = weight;
            next = NULL;
        }     
};

class nodeforLL
{
    public:
        Node * str;
        nodeforLL * next;

        nodeforLL()
        {

        };

        nodeforLL(Node * str)
        {
            this->str = str;
            next = NULL;
        }
};

class LL 
{
    public:
        nodeforLL * head;

        void append(Node * name)
        {
            nodeforLL * n = new nodeforLL (name);

            if(head == NULL)
            {
                head = n;

                return;
            }

            nodeforLL * temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = n;
        }

        bool search(Node * N)
        {
            if(head == NULL)
            {
                return true;
            }

            if(head->str->name == N->name && head->next == NULL)
            {
                return false;
            }

            nodeforLL * temp = head;

            while(temp != NULL)
            {
                if(temp->str->name == N->name)
                {
                    return false;
                }

                temp = temp->next;
            }

            return true;
        }
        
        void replace(Node * scr, Node * dest)
        {
        	nodeforLL * temp = head;
        	
        	while(temp != NULL)
        	{
        		if(temp->str->name == scr->name)
        		{
        			if(temp->str->weight > dest->weight)
        			{
        				temp->str->weight = dest->weight;
					}
					
				}
				temp = temp->next;
			}
		}
		
		char mini()
		{
			char ret;			
			
			int min = 10;
			
			nodeforLL * temp = head;
			
			while(temp != NULL)
			{
				if(temp->str->weight < min)
				{
					ret = temp->str->name;
				}
			}
			
			return ret;
		}

        void display()
        {
            nodeforLL * temp = head;

            while(temp != NULL)
            {
                cout << temp->str->name << " " << temp->str->weight << endl;

                temp = temp->next;
            }
        }
};

class HashTable
{
    public:
        Node ** Table = new Node * [26] {NULL};

        int HashFor(char name)
        {
            return (name % 65);
        }

        void append(char name, int weight)
        {
            Node * n = new Node(name, weight);

            int index = HashFor(name);

            if(Table[index] == NULL)
            {
                Table[index] = n;
            }
            else
            {
                Node * temp = Table[index];

                while(temp->next != NULL)
                {
                    temp = temp->next;
                }

                temp->next = n;
            }
        }

        void edgeconnection(char source, char destination, int a)
        {
            Node * newDes = new Node(destination, a);

            int index = HashFor(source);

            Node * temp = Table[index];

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newDes;
        }

        void Dijstra(char starting)
        {
            char change = starting;

            int weights[6];
            
            int index = HashFor(change);
            
            cout << Table[index]->weight;
        }
};

int main()
{
    HashTable H;

    H.append('S', 0);
    H.append('A', 0);
    H.append('B', 0);
    H.append('C', 0);
    H.append('D', 0);
    H.append('E', 0);

    H.edgeconnection('S', 'A', 1);
    H.edgeconnection('S', 'B', 5);
    H.edgeconnection('A', 'B', 2);
    H.edgeconnection('A', 'C', 2);
    H.edgeconnection('A', 'D', 1);
    H.edgeconnection('C', 'D', 3);
    H.edgeconnection('C', 'E', 1);
    H.edgeconnection('D', 'E', 2);

	Node * n1 = new Node('A', 1);
	Node * n2 = new Node('B', 2);
	Node * n3 = new Node('C', 3);
	Node * n4 = new Node('D', 4);

	
	
    H.Dijstra('S');
}