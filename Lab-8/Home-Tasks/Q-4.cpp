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

        Node(int data, Node * left, Node * right)
        {
            this->data = data;
            this->left = left;
            this->right = right;
        }

        void preorder(Node * r)
        {
            if(r == NULL)
            {
                return;
            }

            cout << r->data << " ";
            preorder(r->left);
            preorder(r->right);
        }
};

class NodeforlinkedList
{
    public:
        Node * data;
        NodeforlinkedList * next;

        NodeforlinkedList()
        {

        };

        NodeforlinkedList(Node * data)
        {
            this->data = data;
            next = NULL;
        }
};

class LL
{
    public:
        NodeforlinkedList * head;

        void insertattail(Node * n)
        {
            NodeforlinkedList * N = new NodeforlinkedList(n);

            if(head == NULL)
            {
                head = N;

                return;
            }

            NodeforlinkedList * temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = N;
        }

        void deleteathead()
        {
            NodeforlinkedList * del = head;

            head = head->next;

            del = NULL;

            delete del;
        }

        void display()
        {
            NodeforlinkedList * temp = head;

            while(temp != NULL)
            {
                temp->data->preorder(temp->data);
                cout << endl;
                temp = temp->next;
            }
        }
};

class BST 
{
    public:
        LL * solve(int a, int b)
        {
            LL * L = new LL();
            LL * L1 = new LL();
            LL * L2 = new LL();

            if(a > b)
            {
                L->insertattail(NULL);

                return L;
            }

            for(int i = a; i <= b; i++)
            {
                L1 = solve(a, i - 1);

                L2 = solve(i + 1, b);

                for(NodeforlinkedList * l = L1->head; l != NULL; l = l->next)
                {
                    for(NodeforlinkedList * r = L2->head; r != NULL; r = r->next)
                    {
                        Node * root = new Node(i);

                        root->left = l->data;

                        root->right = r->data;

                        L->insertattail(root);
                    }
                }
            }
            return L;  
        }
};

int main() 
{
    int n = 0;

    LL * l = new LL();
    
    cout << "Enter the number for unique BST: ";

    cin >> n;

    BST * b = new BST();

    l = b->solve(1, n);

    l->display();
}
