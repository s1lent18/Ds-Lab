#include <iostream>
#include <stack>
using namespace std;

class NodeofLL
{
    public:
        string data;
        int val;
        NodeofLL * next;

        NodeofLL()
        {

        };

        NodeofLL(string data, int val)
        {
            this->data = data;
            this->val = val;
            next = NULL;
        }
};

class LinkedList
{
    public:
        NodeofLL * head;

        LinkedList()
        {
            head = NULL;
        }

        void insertattail(string data, int val)
        {
            NodeofLL * n = new NodeofLL(data, val);

            if(head == NULL)
            {
                head = n;

                return;
            }

            NodeofLL * temp = head;

            while(temp != NULL)
            {
                temp = temp->next;
            }

            temp->next = n;

            return;
        }

        void deleteathead()
        {
            NodeofLL * del = head;

            head = head->next;

            del = NULL;

            delete del;
        } 
};

class Queue
{
    private:
        LinkedList * L = new LinkedList();

    public:
        Queue()
        {
    
        };

        void push(string data, int val)
        {
            L->insertattail(data, val);
        }

        void pop()
        {
           L->deleteathead();
        }

        string Topstring()
        {
            return L->head->data;
        }

        int Topint()
        {
            return L->head->val;
        }

        bool isempty()
        {
            return L->head == NULL;
        }
};

class Node
{
    public:
        char data;
        int val;
        bool visited;
        Node * next;

        Node()
        {

        };

        Node(char data)
        {
            this->data = data;
            visited = false;
            next = NULL;
        }

        Node(char data, int val)
        {
            this->data = data;
            this->val = val;
            visited = false;
            next = NULL;
        }
};

class HashTable
{
    public:
        Node * Table[26];

        int HashFormula(char vertex)
        {
            return (vertex % 97);
        }

        void vertexInsertion(char data)
        {
            Node * n = new Node(data);

            int index = HashFormula(data);

            if(Table[index] == NULL)
            {
                Table[index] = n;
                Table[index]->next = NULL;
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

            int index = HashFormula(source);

            Node * temp = Table[index];

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newDes;

            Node * s = new Node(source, a);

            int index2 = HashFormula(destination);

            temp = Table[index2];

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = s;
        }

        bool check(char arr[], char ch)
        {
            for(int i = 0; i < 6; i++)
            {
                if(arr[i] == ch)
                {
                    return false;
                }
            }
            return true;
        }

        bool checkstring(string arr[], string ch)
        {
            for(int i = 0; i < 6; i++)
            {
                if(arr[i] == ch)
                {
                    return false;
                }
            }
            return true;
        }

        void Prims(char starting)
        {
            char change = starting;

            string traversed[5];
            int traversedweight[5];

            char visitdone[6] = {'#'};

            stack <char>prev;

            int indexforstring = 0;
            int visitindex = 0;

            while (indexforstring != 5)
            {
                int index = HashFormula(change);

                int min = 10;

                Node * temp = Table[index];

                Node * store = Table[index];

                char data = '#'; 

                visitdone[visitindex] = store->data;
                visitindex += 1;

                while (temp != NULL)
                {   
                    if (check(visitdone, temp->data) && temp->val <= min && store->data != temp->data)
                    {
                        min = temp->val;
                        data = temp->data;
                    }
                    temp = temp->next;
                }

                if (data != '#')
                {
                    traversed[indexforstring] = "{ ";
                    traversed[indexforstring] += store->data;
                    traversed[indexforstring] += " ,";
                    traversed[indexforstring] += data;
                    traversed[indexforstring] += " }";
                    traversedweight[indexforstring] = min;  
                    change = data;
                    indexforstring += 1;
                    prev.push(data);
                }
                else if(data == '#')
                {
                    change = prev.top();
                    prev.pop();
                }
            }


        }

        void Kruskals(char starting)
        {
            Queue Q;

            char change = starting;

            string traversed[5];
            int traversedweight[5];
            string traversedtraversed[5];

            char visitdone[6] = {'#'};

            stack <char>prev;

            int indexforstring = 0;
            int visitindex = 0;

            while (indexforstring != 5)
            {
                int index = HashFormula(change);

                int min = 10;

                Node * temp = Table[index];

                Node * store = Table[index];

                char data = '#'; 

                visitdone[visitindex] = store->data;
                visitindex += 1;

                while (temp != NULL)
                {   
                    if (check(visitdone, temp->data) && temp->val <= min && store->data != temp->data)
                    {
                        min = temp->val;
                        data = temp->data;
                    }
                    temp = temp->next;
                }

                if (data != '#')
                {
                    traversed[indexforstring] = "{ ";
                    traversed[indexforstring] += store->data;
                    traversed[indexforstring] += " ,";
                    traversed[indexforstring] += data;
                    traversed[indexforstring] += " }";
                    traversedweight[indexforstring] = min;
                    change = data;
                    indexforstring += 1;
                    prev.push(data);
                }
                else if(data == '#')
                {
                    change = prev.top();
                    prev.pop();
                }
            }
            string temptemp;
            int mine = 10;

            for(int a = 0; a < 5; a++)
            {
                for(int b = 0; b < 5; b++)
                {
                    if(traversedweight[b] <= mine && checkstring(traversedtraversed, traversed[b]))
                    {
                        temptemp = traversed[b];
                        mine = traversedweight[b];
                    }
                }
                Q.push(temptemp, mine);
            }

            for(int i = 0; i < 5; i++)
            {
                cout << Q.Topstring() << endl;
                Q.pop();
            }
        }       
};

int main()
{
    HashTable T;

    T.vertexInsertion('s');
    T.vertexInsertion('a');
    T.vertexInsertion('b');
    T.vertexInsertion('c');
    T.vertexInsertion('d');
    T.vertexInsertion('e');

    T.edgeconnection('s', 'a', 1);
    T.edgeconnection('s', 'b', 5);
    T.edgeconnection('a', 'b', 2);
    T.edgeconnection('a', 'c', 2);
    T.edgeconnection('a', 'd', 1);
    T.edgeconnection('b', 'd', 2);
    T.edgeconnection('c', 'd', 3);
    T.edgeconnection('c', 'e', 1);
    T.edgeconnection('d', 'e', 2);

    T.Prims('s');

    return 0;
}