#include <iostream>
using namespace std;

class Queue
{
    private:
        Node ** arr;
        int front;
        int back;
        int size;

    public:
        Queue(int size)
        {
            arr = new Node*[size];
            front = -1;
            back = -1;
        }

        void push(Node * element)
        {
            if(back == size - 1)
            {
                cout << " Queue OverFlow " << endl;

                return;
            }

            back += 1;

            arr[back] = element;

            if(front == -1)
            {
                front++;
            }
        }   

        void pop()
        {
            if(front == -1 || front > back)
            {
                cout << " Queue Empty " << endl;

                return;
            }

            front += 1;
        }

        Node * peek()
        {
            if(front == -1 || front > back)
            {
                cout << " Queue Empty " << endl;

                return NULL;
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

class Node
{
    public:
        int data;
        Node * left;
        Node * right;
        Node * parent;

        Node()
        {
            left = NULL;
            right = NULL;
            parent = NULL;
        };

        Node(int data)
        {
            this->data = data;
            left = NULL;
            right = NULL;
            parent = NULL;
        }
};

class BT
{
    public:
        Node * root;

        BT()
        {
            root = NULL;
        }

        void heapify()
        {
            Node * temp = root;

            
        }

        void insertion(int data)
        {
            Node * n = new Node(data);

            if(root == NULL)
            {
                root = n;

                return;
            }

            Queue Q(10);
            
            Node * temp;

            Q.push(root);
            
            while(!Q.isempty())
            {
                temp = Q.peek();
                
                Q.pop();

                if(temp->left == NULL)
                {
                    temp->left = n;

                    n->parent = temp->left;

                    break;
                }
                else
                {
                    Q.push(temp->left);
                }

                if(temp->right == NULL)
                {
                    temp->right = n;

                    n->parent = temp->right;

                    break;
                }
                else
                {
                    Q.push(temp->right);
                }
            }


        }
};