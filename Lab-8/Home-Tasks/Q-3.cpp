#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node * left;
        Node * right;

        Node()
        {

        }

        Node(int data)
        {
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

