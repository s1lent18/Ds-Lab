#include <iostream>
using namespace std;

class NodeforBST
{
    public:
        int data;
        NodeforBST * left;
        NodeforBST * right;

        NodeforBST()
        {

        }

        NodeforBST(int data)
        {
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

class BST
{
    public:
        NodeforBST * root;

        NodeforBST * Insert(NodeforBST *& head, int data)
        {
            if(head == NULL)
            {
                NodeforBST * n = new NodeforBST(data);

                head = n;

                return head;
            }

            if(data > head->data)
            {
                Insert(head->right, data);
            }
            else if(data < head->data)
            {
                Insert(head->left, data);
            }
            return head;
        }

        int Sum(NodeforBST * head)
        {
            if(head == NULL)
            {
                return 0;
            }

            int leftsum = Sum(head->left);
            int rightsum = Sum(head->right);

            return head->data + leftsum + rightsum;
        }


};

class NodeforBT
{
    public:
        BST * data;
        NodeforBT * left;
        NodeforBT * right;
        int sum;

        NodeforBT()
        {

        }

        NodeforBT(BST * data)
        {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        int totalSum()
        {
            sum = data->Sum(data->root);
            return sum;
        }
};

class NodeQueue
{
    public:
        NodeforBT * data;
        NodeQueue * next;

        NodeQueue()
        {

        }

        NodeQueue(NodeforBT * data)
        {
            this->data = data;
            next = NULL;
        }
};

class LinkedList
{
    public:
        NodeQueue * head;

        void insertattail(NodeforBT * data)
        {
            NodeQueue * n = new NodeQueue(data);

            if(head == NULL)
            {
                head = n;

                return;
            }

            NodeQueue * temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = n;
        }

        void deleteathead()
        {
            NodeQueue * del = head;

            head = head->next;

            del = NULL;

            delete del;
        }

        NodeforBT * Last()
        {
            return head->data;
        }
};

class Queue
{
    public:
        LinkedList * L = new LinkedList();

        void enqueue(NodeforBT * N)
        {
            L->insertattail(N);
        }

        void dequeue()
        {
            L->deleteathead();
        }

        NodeforBT * Top()
        {
            L->Last();
        }

        bool isempty()
        {
            return L->head == NULL;
        }
};

class BT
{
    public:
        NodeforBT * root;

        void Insert(BST * n)
        {
            NodeforBT * N = new NodeforBT(n);

            if(root == NULL)
            {
                root = N;

                return;
            }

            NodeforBT * temp;

            Queue Q;

            Q.enqueue(root);

            while(!Q.isempty())
            {
                temp = Q.Top();

                Q.dequeue();

                if(temp->left == NULL)
                {
                    temp->left = N;

                    break;
                }
                else
                {
                    Q.enqueue(temp->left);
                }

                if(temp->right == NULL)
                {
                    temp->right = N;

                    break;
                }
                else
                {
                    Q.enqueue(temp->right);
                }
            }
        }

        int maxsum(NodeforBT *& head)
        {
            if(head == NULL)
            {
                return 0;
            }

            int leftsum = maxsum(head->left);
            int rightsum = maxsum(head->right);

            return max(max(leftsum, rightsum), head->totalSum());
        }
};

int main()
{
    BST * B1 = new BST();
    BST * B2 = new BST();
    BST * B3 = new BST();

    B1->Insert(B1->root, 1);
    B2->Insert(B2->root, 4);
    B2->Insert(B2->root, 2);
    B2->Insert(B2->root, 4);
    B3->Insert(B3->root, 3);
    B3->Insert(B3->root, 2);
    B3->Insert(B3->root, 5);
    B3->Insert(B3->root, 4);
    B3->Insert(B3->root, 6);

    BT * B = new BT();

    B->Insert(B1);
    B->Insert(B2);
    B->Insert(B3);

    cout << B->maxsum(B->root);

}