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

int height(Node *& root)
{
    if(root == NULL)
    {
        return 0;
    }

    int leftH = height(root->left);
    int rightH = height(root->right);

    return max(leftH, rightH) + 1;
}

bool PBT(Node *& root, int depth, int level)
{   
    if(root == NULL)
    {
        return 1;
    }

    if(root->left == NULL && root->right == NULL)
    {
        if(depth == level)
        {
            return 1;
        }
        return 0;
    }

    return PBT(root->left, depth, level + 1) && PBT(root->right, depth, level + 1);
}

// considering that the minimum value that can be stored in the tree is -1
// considering that the maximum value that can be stored in the tree is 1000

bool BST(Node *&root, int min = -1, int max = 1000)
{
    if(root == NULL)
    {
        return true;
    }

    if(root->data <= min || root->data >= max)
    {
        return false;
    }

    return BST(root->left, min, root->data) && BST(root->right, root->data, max);
}

bool CBT(Node *& root)
{
    if(root == NULL)
    {
        return true;
    }

    Queue Q;

    bool flag = 0;

    Q.enqueue(root);

    Node * temp;

    while(!Q.isempty())
    {
        temp = Q.Top();
        Q.dequeue();

        if(temp == NULL)
        {
            flag = 1;
        }
        else
        {
            if(flag)
            {
                return false;
            }
        }

        Q.enqueue(root->left);
        Q.enqueue(root->right);
    }
    return true;
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

    int d = height(B->root);

    if(PBT(B->root, d, 0))
    {
        cout << "Perfect Binary Tree" << endl;
    }
    else
    {
        cout << "Not Perfect binary tree " << endl;
    }

    if(BST(B->root))
    {
        cout << "Binary Search Tree" << endl;
    }
    else
    {
        cout << "Not binary search tree " << endl;
    }

    if(CBT(B->root))
    {
        cout << "Complete Binary Tree" << endl;
    }
    else
    {
        cout << "Not Complete binary tree " << endl;
    }
}
