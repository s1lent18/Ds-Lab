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
            data = 0;
            left = NULL;
            right = NULL;
        };

        Node(int data)
        {
            this->data = data;
            left = NULL;
            right = NULL;
        }

};

class Nodeq
{
    public:
        Node * val;
        Nodeq * next;

        Nodeq(Node * val)
        {
            this->val = val;
            next = NULL;
        }
};

class LinkedList
{
    public:
        Nodeq * head;

        void insertattail(Node * data)
        {
            Nodeq * n = new Nodeq(data);

            if(head == NULL)
            {
                head = n;

                return;
            }

            Nodeq * temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = n;
        }

        void deleteathead()
        {
            Nodeq * temp = head;

            head = head->next;

            temp = NULL;

            delete temp;
        }

        Node * last()
        {
            return head->val;
        }
};

class Queue
{
    public:
        LinkedList * L = new LinkedList();
        
        void enqueue(Node * data)
        {
            L->insertattail(data);
        }

        void dequeue()
        {
            L->deleteathead();
        }

        Node * Top()
        {
            return L->last();
        }

        bool isempty()
        {
            return L->head == NULL;
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

        void Insertion(int data)
        {
            Node * insert = new Node(data);
        	
			if(root == NULL)
        	{
        		root = insert;
        		
        		return;
			}
        	
            Node * temp;

            Queue Q;

            Q.enqueue(root);
            
            while(!Q.isempty())
            {
                temp = Q.Top();
                
                Q.dequeue();

                if(temp->left == NULL)
                {
                    temp->left = insert;
                    break;
                }
                else
                {
                    Q.enqueue(temp->left);
                }

                if(temp->right == NULL)
                {
                    temp->right = insert;
                    break;
                }
                else
                {
                    Q.enqueue(temp->right);
                }
            }
        }
};

void preorder(Node * root)
{
    if(root == NULL)
    {
        return; 
    }

    cout << root->data << " " ;

    preorder(root->left);
    preorder(root->right);
}

int main()
{
    BT * B = new BT();

    int array[8] = {1, 2, 3, 4, 5, 6, 7, 8};

    for(int i = 0; i < 8; i++)
    {
        B->Insertion(array[i]);
    }

    preorder(B->root);
}
