#include <iostream>
#include <stack>
using namespace std;

class nodeforLL
{
    public:
        char name;
        nodeforLL * next;

        nodeforLL()
        {

        };

        nodeforLL(char name)
        {
            this->name = name;
            next = NULL;
        }
};

class LL 
{
    public:
        nodeforLL * head;

        void append(char name)
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

        bool search(char name)
        {
            if(head == NULL)
            {
                return true;
            }

            if(head->name == name && head->next == NULL)
            {
                return false;
            }

            nodeforLL * temp = head;

            while(temp != NULL)
            {
                if(temp->name == name)
                {
                    return false;
                }

                temp = temp->next;
            }

            return true;
        }

        void display()
        {
            nodeforLL * temp = head;

            while(temp != NULL)
            {
                cout << temp->name << " " ;

                temp = temp->next;
            }
        }
};

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
            stack <char> S;

            S.push('#');

            char change = starting;

            int MstCost = 0;

            LL * visited = new LL();

            bool flag = false;

            while(!S.empty())
            {
                int inx = HashFor(change);

                int min = 10;

                Node * temp = Table[inx];

                Node * store = Table[inx];
                
                if(visited->search(temp->name))
                {
                    visited->append(temp->name);
                    
                    S.push(temp->name);
                }

                while(temp != NULL)
                {
                    if(temp->weight < min && visited->search(temp->name))
                    {
                        min = temp->weight;

                        change = temp->name;
                    }
                    
                    temp = temp->next;
                }
                
                if(flag)
                {
                    if(change != store->name)
                    {
                        S.push(store->name);
                    }
                    flag = false;
                }
                
                if(visited->search(change))
                {
                    MstCost += min;
                    
                    S.push(change);
                    
                    visited->append(change);
                }
                else
                {
                    flag = true;
                    change = S.top();
                    S.pop();
                }
                
                
            }
            visited->display();
            
            cout << endl;
            
            cout << "The MST cost is " << MstCost << endl;
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

    H.Dijstra('S');
}