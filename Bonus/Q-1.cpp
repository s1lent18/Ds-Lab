#include <iostream>
using namespace std;

const int maxe = 10;

int getmax(int a, int b)
{
    if(a >= b)
    {
        return a;
    }
    return b;
}

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

        void addedge(int source, int dest, int weight)
        {
            adjacencymatrix[source][dest] = weight;
            adjacencymatrix[dest][source] = weight;
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

        static Graph combine(Graph & G1, Graph & G2)
        {
            int size1 = G1.numberofvertices;
            int size2 = G2.numberofvertices;

            Graph G3(getmax(size1, size2));
            
            for(int i = 0; i < size1; i++)
            {
                for(int j = 0; j < size1; j++)
                {
                    if(G1.adjacencymatrix[i][j] != 0)
                    {
                        G3.addedge(i, j, G1.adjacencymatrix[i][j]);
                    }
                }
            }

            for(int i = 0; i < size2; i++)
            {
                for(int j = 0; j < size2; j++)
                {
                    if(G2.adjacencymatrix[i][j] != 0)
                    {
                        if(G3.adjacencymatrix[i][j] > G2.adjacencymatrix[i][j] && G3.adjacencymatrix[i][j] != 0)
                        {
                            G3.addedge(i, j, G2.adjacencymatrix[i][j]);
                        }
                        else if(G3.adjacencymatrix[i][j] == 0)
                        {
                            G3.addedge(i, j, G2.adjacencymatrix[i][j]);
                        }
                    }
                }
            }

            return G3;
        }
};

int main()
{
    Graph G1(5);

    G1.addedge(0, 0, 2);
    G1.addedge(0, 1, 2);
    G1.addedge(0, 3, 2);
    G1.addedge(1, 2, 2);
    G1.addedge(1, 0, 2);
    G1.addedge(4, 4, 2);

    Graph G2(3);

    G2.addedge(0, 0, 1);
    G2.addedge(0, 2, 1);
    G2.addedge(4, 4, 1);

    Graph G3 = Graph::combine(G1, G2);

    G3.printgraph();
}