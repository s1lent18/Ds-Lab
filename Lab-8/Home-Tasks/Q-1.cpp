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

        };

        Node(int data)
        {
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

class Nodeforqueue
{
    public:
        Node * val;
        Nodeforqueue * next;

        Nodeforqueue()
        {

        };

        Nodeforqueue(Node * val)
        {
            this->val = val;
            next = NULL;
        }
};

class LinkedList
{
    public:
        Nodeforqueue * head;

        void insertattail(Node * val)
        {
            Nodeforqueue * n = new Nodeforqueue(val);

            if(head == NULL)
            {
                head = n;

                return;
            } 

            Nodeforqueue * temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = n;
        }

        void deleteathead()
        {
            Nodeforqueue * del = head;

            head = head->next;

            del = NULL;

            delete del;
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

        void enqueue(Node * val)
        {
            L->insertattail(val);
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

        void insertion(Node *& head, int data)
        {
            Node * insert = new Node(data);

            if(head == NULL)
            {
                head = insert;

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


bool FBT(Node *& head)
 {
    if(head == NULL) 
    {
        return false;
    }
    if (head->left == NULL && head->right == NULL) 
    {
        return true;
    }
    if (head->left != NULL && head->right != NULL) 
    {
        return FBT(head->left) && FBT(head->right);
    }
    return false;
}

int main()
{
    BT * B = new BT();

    B->insertion(B->root, 1);
    B->insertion(B->root, 2);
    B->insertion(B->root, 3);
    B->insertion(B->root, 4);
    B->insertion(B->root, 5);

    if(FBT(B->root))
    {
        cout << "Full Binary Tree" << endl;
    }
    else
    {
        cout << "Not full binary tree " << endl;
    }
}
