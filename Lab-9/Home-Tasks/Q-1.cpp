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

		int kthminvalue(Node * root, int k)
		{
			if(root == NULL)
			{
				return 0;
			}

			int l = getheight(root->left) + 1;

			if(k == l)
			{
				return root->data;
			}
			else if(k < l)
			{
				return kthminvalue(root->left, k);
			}
			else
			{
				return kthminvalue(root->right, k - l);
			}
		}

		int kthmaxvalue(Node * root, int k)
		{
			if(root == NULL)
			{
				return 0;
			}

			int r = getheight(root->right) + 1;

			if(k == r)
			{
				return root->data;
			}
			else if(k < r)
			{
				return kthminvalue(root->right, k);
			}
			else
			{
				return kthminvalue(root->left, k - r);
			}
		}
			
};



int main()
{
	Tree * T = new Tree();
	
	for(int i = 1; i < 8; i++)
	{
		T->root = T->insert(T->root, i);
	}

	cout << T->kthminvalue(T->root, 2) << endl;
	cout << T->kthmaxvalue(T->root, 2);
}
