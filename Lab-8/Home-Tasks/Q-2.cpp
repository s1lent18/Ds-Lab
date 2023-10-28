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

class BST
{
    public:
        Node * root;

        Node * insert(int data, Node *& head)
        {
            if(head == NULL)
            {
                Node * b = new Node(data);

                head = b;
            }
            else if(data <= head->data)
            {
                head->left = insert(data, head->left);
            }
            else if(data >= head->data)
            {
                head->right = insert(data, head->right);
            }
            return head;
        }

        Node * deleteallduplicates(Node *& head)
        {
            if(head == NULL)
            {
                return NULL;
            }

            head->left = deleteallduplicates(head->left);
            head->right = deleteallduplicates(head->right);

            if(head->left != NULL)
            {
                if(head->left->data == head->data)
                {
                    Node * temp = head->left;

                    head = NULL;

                    delete head;

                    return temp;
                }
            }

            if(head->right != NULL)
            {
                if(head->right->data == head->data)
                {
                    Node * temp = head->right;

                    head = NULL;

                    delete head;

                    return temp;
                }
            }

            return head;
        }

        Node * search(Node *& head, int data)
        {
            if(head == NULL)
            {
                return NULL;
            }
            else if(data < head->data)
            {
                return search(head->right, data);
            }
            else if(data > head->data)
            {
                return search(head->left, data);
            }
            else
            {
                return head;
            }
        }  

        
};

void preorder(Node * root)
{
    if(root == NULL)
    {
        return; 
    }

    cout << root->data << " ";

    preorder(root->left);
    preorder(root->right);
}

int main()
{
    BST * B = new BST();

    B->insert(54, B->root);
    B->insert(23, B->root);
    B->insert(10, B->root);
    B->insert(67, B->root);
    B->insert(10, B->root);
    B->insert(40, B->root);
    B->insert(90, B->root);
    B->insert(40, B->root);
    B->insert(2, B->root);
    B->insert(23, B->root);

    preorder(B->root);

    B->deleteallduplicates(B->root);

    cout << endl;

    preorder(B->root);

}