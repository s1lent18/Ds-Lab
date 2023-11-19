#include <iostream>
using namespace std;

class Nodefortree
{
    public:
        int data;
        Nodefortree * left;
        Nodefortree * right;
        Nodefortree * parent;

        Nodefortree()
        {

        }

        Nodefortree(int data)
        {
            this->data = data;
            parent = NULL;
            left = NULL;
            right = NULL;
        }
};

class Node
{
    public:
        Nodefortree * data = new Nodefortree();
        Node * next;

        Node()
        {

        };

        Node(Nodefortree * data)
        {
            this->data = data;
            next = NULL;
        }
};

class LL
{
    public:
        Node * head;

        void append(Nodefortree * data)
        {
            Node * n = new Node(data);

            if(head == NULL)
            {
                head = n;

                return;
            }

            Node * temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = n;
        }

        void deleteathead()
        {
            Node * del = head;

            head = head->next;

            del = NULL;

            delete del;
        }

        Nodefortree * headreturn()
        {
            return head->data;
        }

        bool isempty()
        {
            return head == NULL;
        }
};

class Queue
{
    public:
        LL * L = new LL();
        
        void enqueue(Nodefortree * data)
        {
            L->append(data);
        }

        void dequeue()
        {
            L->deleteathead();
        }

        Nodefortree * Top()
        {
            return L->headreturn();
        }

        bool isempty()
        {
            L->isempty();
        }

};

class Heap
{
    public:
        Nodefortree * root;

        void Insert(int data)
        {
            Nodefortree * insert = new Nodefortree(data);

            if(root == NULL)
            {
                root = insert;

                insert->parent = root;

                return;
            }

            Queue Q;

            Q.enqueue(root);

            Nodefortree * temp;

            while(!Q.isempty())
            {
                temp = Q.Top();
                Q.dequeue();

                if(temp->left == NULL)
                {
                    temp->left = insert;
                    insert->parent = temp;
                    break;
                }
                else
                {
                    Q.enqueue(temp->left);
                }
                
                if(temp->right == NULL)
                {
                    temp->right = insert;
                    insert->parent = temp;
                    break;
                }
                else
                {
                    Q.enqueue(temp->right);
                }
            }

            NodeSwap(insert);

        }

        void inorder(Nodefortree * root)
        {
            if(root == NULL)
            {
                return;
            }

            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }

        void NodeSwap(Nodefortree *& root)
        {
            if(root->parent == NULL)
            {
                return;
            }

            if(root->data < root->parent->data)
            {
                swap(root->data, root->parent->data);
                NodeSwap(root->parent);
            }

        }

        void rebalance(Nodefortree *& root)
        {
            if(root == NULL)
            {
                return;
            }

            if(root->parent != NULL && root->data > root->parent->data)
            {
                swap(root->data, root->parent->data);
                rebalance(root->parent);
            }
            rebalance(root->left);
            rebalance(root->right);
        }

};

int main()
{
    Heap * H = new Heap();

    H->Insert(35);
    H->Insert(33);
    H->Insert(42);
    H->Insert(10);
    H->Insert(14);
    H->Insert(19);
    H->Insert(27);
    H->Insert(44);
    H->Insert(26);
    H->Insert(31);

    H->inorder(H->root);

    H->rebalance(H->root);

    cout << endl;

    H->inorder(H->root);
}