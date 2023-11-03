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

        Node * insert(int data, Node*& head) 
        {
            if (head == NULL) 
            {
                Node* newNode = new Node(data);

                head = newNode;

            } else if (data < head->data) 
            {
                head->left = insert(data, head->left);

            } else if (data > head->data) 
            {
                head->right = insert(data, head->right);

            }
            return head;
        }

        Node * Min(Node* head) 
        {
            if (head == NULL) 
            {
                return NULL;

            } else if (head->left == NULL) 
            {
                return head;

            } else 
            {
                return Min(head->left);
            }
        }

        Node * deletebyvalue(Node*& head, int data) 
        {
            if (head == NULL) 
            {
                return NULL;
            }
            if (data < head->data) 
            {
                head->left = deletebyvalue(head->left, data);

            } else if (data > head->data) 
            {
                head->right = deletebyvalue(head->right, data);

            } else 
            {
                if (head->left == NULL) 
                {
                    Node * temp = head->right;

                    delete head;

                    return temp;

                } else if (head->right == NULL) 
                {
                    Node * temp = head->left;

                    delete head;

                    return temp;
                }

                Node * temp = Min(head->right);

                head->data = temp->data;

                head->right = deletebyvalue(head->right, temp->data);
            }
            return head;
        }

        void S(string a, int d, Node*& head) 
        {
            bool ai = false;
            bool bi = false;

            if (a == "ceil") 
            {
                ai = search(head, d + 1);

            } else if (a == "floor") 
            {
                bi = search(head, d - 1);
            }

            if (ai) 
            {
                deletebyvalue(head, d + 1);

            } else if (bi) 
            {
                deletebyvalue(head, d - 1);
            }
        }

        bool search(Node *& head, int data) 
        {
            if (head == NULL) 
            {
                return false;

            } else if (data < head->data) 
            {
                return search(head->left, data);

            } else if (data > head->data) 
            {
                return search(head->right, data);

            } else if (data == head->data) 
            {
                return true;
            }
            return false;
        }
};

void preorder(Node * root) 
{
    if (root == NULL) 
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
    B->insert(67, B->root);
    B->insert(10, B->root);
    B->insert(40, B->root);
    B->insert(90, B->root);
    B->insert(2, B->root);

    preorder(B->root);
    
    cout << endl;

    B->search(B->root, 23);

    B->S("ceil", 22, B->root);

    preorder(B->root);

    return 0;
}
