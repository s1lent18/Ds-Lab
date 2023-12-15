#include <iostream>
#include <stack>
using namespace std;

class Stack
{
    private:
        char * arr;
        int top;
        int size;

    public:
        Stack()
        {
            size = 10;
            arr = new char[10];
            top = -1;
        }

        Stack(char size)
        {
            this->size = size;
            arr = new char[size];
            top = -1;
        }

        void push(char element)
        {
            if(top == size - 1)
            {
                cout << "Stack OverFlow " << endl;

                return;
            }

            top += 1;
            arr[top] = element;
        }

        void pop()
        {
            if(top == - 1)
            {
                cout << "Stack Empty no element to pop " << endl;

                return;  
            }

            top -= 1;
        }

        char Top()
        {
            if(top == - 1)
            {
                cout << "Stack Empty no element to pop " << endl;

                return -1;
            }

            return arr[top];
        }

        bool empty()
        {
            return top == -1;
        }

};

const int maxe = 10;

class Graph
{
    private:
        int numberofvertices;
        int adjacencymatrix[maxe][maxe];

    public:
        Graph(int numberofvertices)
        {
            this->numberofvertices = numberofvertices;

            for(int i = 0; i < maxe; i++)
            {
                for(int j = 0; j < maxe; j++)
                {
                    adjacencymatrix[i][j] = 0;
                }
            }
        }

        void addedge(char source, char dest)
        {
            adjacencymatrix[source % 65][dest % 65] = 1;
        }

        void Q3()
        {
            int count = 0;

            for(int i = numberofvertices - 1; i >= 0; i--)
            {
                if(adjacencymatrix[i][numberofvertices - 1] == 1)
                {
                    count++;
                }
            }

            Stack * array = new Stack[count];

            int * arr = new int[count];
            
            for(int i = 0; i < count; i++)
            {
                array[i].push(numberofvertices + 64);
            }

            int index = 0;

            for(int i = numberofvertices - 1; i >= 0; i--)
            {
                if(adjacencymatrix[i][numberofvertices - 1] == 1)
                {
                    array[index].push(i + 65);
                    arr[index] = 1;
                    index++;
                }
            }

            for(int i = 0; i < index; i++)
            {
                while(array[i].Top() != 'A')
                {
                    int k = array[i].Top() % 65;

                    for(int j = numberofvertices - 1; j >= 0; j--)
                    {
                        if(adjacencymatrix[j][k] == 1)
                        {
                            array[i].push(j + 65);
                            arr[i]++;
                        }
                    }
                }

                while(!array[i].empty())
                {
                    cout << array[i].Top() << " ";

                    array[i].pop();
                }

                
                cout << "  MST COST: " << arr[i];
                
                cout << endl;
            }
        }

        void printgraph()
        {
            for(int i = 0; i < numberofvertices; i++)
            {
                for(int j = 0; j < numberofvertices; j++)
                {
                    cout << adjacencymatrix[i][j] << " ";
                }
                cout << endl;
            }
        }
};

int main()
{
    Graph G(7);

    G.addedge('A', 'B');
    G.addedge('A', 'C');
    G.addedge('A', 'D');
    G.addedge('B', 'E');
    G.addedge('C', 'E');
    G.addedge('D', 'F');
    G.addedge('E', 'G');
    G.addedge('F', 'G');

    G.Q3();
}