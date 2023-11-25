#include <iostream>
using namespace std;

class UndirGraph
{
    public:
        int numberofvertices;
        char ** mat = new char*[numberofvertices];

        UndirGraph()
        {
            for(int i = 0; i < numberofvertices; i++)
            {
                mat[i] = new char[numberofvertices];
            }
        }

        void addvertex(char source, char destination)
        {
            
        }


};