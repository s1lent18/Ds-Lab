#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
    public:
        int data;
        int height;
        Node * left;
        Node * right;

		Node()
		{
		}

        Node(int data)
        {
            this->data = data;
            height = 1;
            left = NULL;
            right = NULL;
        }

};

class Tree
{
	public:
		Node * root;
		
		Tree()
		{
			root = NULL;
		}
		
		int getheight(Node * n)
		{
		    if(n == 0)
		    {
		        return 0;
		    }
		
		    return n->height;
		}
		
		int max(int a, int b)
		{
		    if(a > b)
		    {
		    	return a;
			}
			return b;
		}
		
		Node * rotateright(Node * root)
		{
		    Node * afterroot = root->left;
		    Node * temp = afterroot->right;
		
		    afterroot->right = root;
		    root->left = temp;
		
		    root->height = max(getheight(root->left), getheight(root->right)) + 1;
		    
		    afterroot->height = max(getheight(afterroot->left), getheight(afterroot->right)) + 1;
		
		    return afterroot;
		}
		
		Node * rotateleft(Node * root)
		{
		    Node * afterroot = root->right;
		    Node * temp = afterroot->left; 
		
		    afterroot->left = root;
		    root->right = temp;
		
		    root->height = max(getheight(root->left), getheight(root->right)) + 1;
		    
		    afterroot->height = max(getheight(afterroot->left), getheight(afterroot->right)) + 1;
		
		    return afterroot;
		}
		
		int getbalancingfactor(Node * n)
		{
		    if(n == NULL)
		    {
		        return 0;
		    }
		
		    return getheight(n->left) - getheight(n->right);
		}
		
		Node * insert(Node * root, int data)
		{
		    if(root == NULL)  
		    {
		        Node * n = new Node(data);
		
		        return n;
		    }
		
		    if(data < root->data)
		    {
		        root->left = insert(root->left, data);
		    }
		
		    if(data > root->data)
		    {
		        root->right = insert(root->right, data);
		    }
		
		    if(data == root->data)
		    {
		        return root;
		    }
		
		    root->height = max(getheight(root->left), getheight(root->right)) + 1;  
		
		    int balance = getbalancingfactor(root);

		    if(balance > 1 && data < root->left->data)
		    {
		        return rotateright(root);
		    }
		
		    if(balance < -1 && data > root->right->data)
		    {
		        return rotateleft(root);
		    }
		
		    if(balance > 1 && data > root->left->data)
		    {
		        root->left = rotateleft(root->left);
		        return rotateright(root);
		    }
		
		    if(balance < -1 && data < root->right->data)
		    {
		        root->right = rotateright(root->right);
		        return rotateleft(root);
		    }
		
		    return root;
		}
		
		void inorder(Node * n)
		{
		    if(n == NULL)
		    {
		        return;
		    }
		
		    inorder(n->left);
		    cout << n->data << " ";
		    inorder(n->right);
		}

		void preorder(Node * n)
		{
			if(n == NULL)
			{
				return;
			}

			cout << n->data << " ";
			
			preorder(n->left);
			
			preorder(n->right);
		}

		void postorder(Node * n)
		{
			if(n == NULL)
			{
				return;
			}

			postorder(n->left);			
	
			postorder(n->right);
			cout << n->data << " ";
		}
			
};

int main()
{
	Tree * T = new Tree();
	
	for(int i = 1; i < 8; i++)
	{
		T->root = T->insert(T->root, i);
	}

    T->inorder(T->root);
	cout << endl;
	T->preorder(T->root);
	cout << endl;
	T->postorder(T->root); 
}
