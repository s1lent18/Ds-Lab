#include <iostream>
using namespace std;

class Node
{
    public:
        char data;
        Node * next;

        Node()
        {

        };

        Node(char data)
        {
            this->data = data;
            next = NULL;
        }
};

class Stack
{
    private:
        char * arr;
        int top;
        int size;

    public:
        Stack(int size)
        {
            this->size = size;
            arr = new char[size];
            top = -1;
        }

        void push(char data)
        {
            if(top == size - 1)
            {
                cout << "Stack Overflow" << endl;

                return;
            }

            top += 1;

            arr[top] = data;
        }

        void pop()
        {
            if(top == -1)
            {
                cout << "Stack Empty" << endl;

                return;
            }

            top -= 1;
        }

        char Top()
        {
            return arr[top];
        }

        bool isempty()
        {
            return top == -1;
        }
};

class Queue
{
    private:
        char * arr;
        int front;
        int back;
        int size;

    public:
        Queue(int size)
        {
            this->size = size;
            arr = new char[size];
            front = -1;
            back = -1;
        }

        void enqueue(char data)
        {
            if(back == size - 1)
            {
                cout << "Queue OverFlow" << endl;

                return;
            }

            back += 1;

            arr[back] = data;

            if(front == -1)
            {
                front++;
            }
        }

        void dequeue()
        {
            if(front == -1 || front > back)
            {
                cout << "Queue Empty" << endl;

                return;
            }

            front += 1;
        }

        char peek()
        {
            if(front == -1 || front > back)
            {
                cout << " Queue Empty " << endl;

                return ' ';
            }

            return arr[front];
        }

        bool isempty()
        {
            if(front == -1 || front > back)
            {
                return 1;
            }
            return 0;
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

        void edgeconnection(char source, char destination)
        {
            Node * newDes = new Node(destination);

            int index = HashFormula(source);

            Node * temp = Table[index];

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newDes;

            Node * s = new Node(source);

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
            for(int i = 0; i < 26; i++)
            {
                if(arr[i] == ch)
                {
                    return false;
                }
            }
            return true;
        }

        void DFS()
        {
            Stack S(26);
            
            Node * temp;

            char visited[26] = {'#'};
            
            int index = 0;

            temp = Table[0];

            visited[index] = temp->data;

            index += 1;

            while(temp != NULL)
            {
                S.push(temp->data);

                temp = temp->next;
            }

            while(!S.isempty())
            {
                char p = S.Top();
                S.pop();

                if(check(visited, p))
                {
                    visited[index] = p;

                    index ++;

                    for(int i = 0; i < 26; i++)
                    {
                        if(Table[i]->data == p)
                        {
                            temp = Table[i];

                            while(temp != NULL)
                            {
                                S.push(temp->data);

                                temp = temp->next;
                            }
                            break;
                        }
                    }
                }
            }

            for(int i = 0; i < 26; i++)
            {
                if(visited[i] >= 'a' && visited[i] <= 'z')
                {
                    cout << visited[i] << " -> ";
                }
            }
            
        }

        void BFS()
        {
            Queue Q(26);

            Node * temp;

            char visited[26] = {'#'};
            
            int index = 0;

            temp = Table[0];

            visited[index] = temp->data;

            index += 1;

            while(temp != NULL)
            {
                Q.enqueue(temp->data);

                temp = temp->next;
            }

            while(!Q.isempty())
            {
                char p = Q.peek();
                Q.dequeue();

                if(check(visited, p))
                {
                    visited[index] = p;

                    index ++;

                    for(int i = 0; i < 26; i++)
                    {
                        if(Table[i]->data == p)
                        {
                            temp = Table[i];

                            while(temp != NULL)
                            {
                                Q.enqueue(temp->data);

                                temp = temp->next;
                            }
                            break;
                        }
                    }
                }
            }

            for(int i = 0; i < 26; i++)
            {
                if(visited[i] >= 'a' && visited[i] <= 'z')
                {
                    cout << visited[i] << " -> ";
                }
            }
        }
};

int main()
{
    HashTable T;

    T.vertexInsertion('a');
    T.vertexInsertion('b');
    T.vertexInsertion('c');
    T.vertexInsertion('d');
    T.vertexInsertion('e');
    T.vertexInsertion('e');
    T.vertexInsertion('f');

    T.edgeconnection('a', 'b');
    T.edgeconnection('a', 'c');
    T.edgeconnection('b', 'c');
    T.edgeconnection('b', 'd');
    T.edgeconnection('b', 'e');
    T.edgeconnection('c', 'd');
    T.edgeconnection('c', 'f');
    T.edgeconnection('d', 'e');
    T.edgeconnection('d', 'f');
    T.edgeconnection('e', 'e');
    T.edgeconnection('e', 'f');
    T.edgeconnection('f', 'e');

    T.DFS();

    cout << endl << endl;

    T.BFS();

}