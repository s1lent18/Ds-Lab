#include <iostream>

using namespace std;

template <class T>
class Node
{
    public:
        T data;
        Node<T> * next;

        Node()
        {

        };

        Node(T data)
        {
            this->data = data;
            next = NULL;
        }
};

template <class T>

class LinkedList
{
    public:
        Node<T>* head;

        void append(T data)
        {
            Node<T> * n = new Node<T>(data);

            if(head == NULL)
            {
                head = n;

                return;
            }

            Node<T> * temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = n;
        } 
};

class Graph
{
    public:
        int size;
        LinkedList <int>* vertex;

        Graph(int size)
        {
            this->size = size;
            vertex = new LinkedList<int>[size];
        }

        void connection(int source, int destination)
        {
            vertex[source].append(destination);
            vertex[destination].append(source);
        }

        void printmatrix()
        {
            int array[5][5] = {0};

            for(int i = 0; i < size; i++)
            {
                Node <int> * temp = vertex[i].head;

                while(temp != NULL)
                {
                    array[i][temp->data] = 1;
                    
                    temp = temp->next;
                }
            }

            for(int i = 0; i < 5; i++)
            {
                for(int j = 0; j < 5; j++)
                {
                    cout << array[i][j] << ", ";
                }
                cout << endl;
            }
        }
};

int main()
{
    Graph G(5);
    
    G.connection(0, 1);
    G.connection(0, 4);
    G.connection(4, 1);
    G.connection(4, 3);
    G.connection(1, 3);
    G.connection(1, 2);
    G.connection(3, 2);

    G.printmatrix();
}