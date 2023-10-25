#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node * left;
        Node * right;

        Node(int data)
        {
            this->data = data;
            left = NULL;
            right = NULL;
        }

};

class BST
{
    public:
        Node * root;

        BST()
        {
            root = NULL;
        }

        Node * insert(int data, Node *& head)
        {
            if(head == NULL)
            {
                Node * b = new Node(data);

                head = b;
            }
            else if(data < head->data)
            {
                head->left = insert(data, head->left);
            }
            else if(data > head->data)
            {
                head->right = insert(data, head->right);
            }
            return head;
        }

        int search(Node *& head, int data)
        {
            if(head == NULL)
            {
                return NULL;
            }
            else if(data < head->data)
            {
                return search(head->left, data);
            }
            else if(data > head->data)
            {
                return search(head->right, data);
            }
            else
            {
                return head->data;
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
    BST * b = new BST();

    int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};

    for(int i = 0; i < 8; i++)
    {
        b->insert(arr[i], b->root);
    }

    preorder(b->root);

    int sear = 0;

    cout << endl << "Enter a value to search: ";

    cin >> sear;

    if(b->search(b->root, sear) == sear)
    {
        cout << "Found";
    }
    else
    {
        cout << "not Found";
    }

    return 0;
}