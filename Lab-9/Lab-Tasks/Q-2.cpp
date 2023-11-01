#include <iostream>
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
			
		};
		
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
			root = nullptr;
		}

		int max(int a, int b)
		{
			if(a > b)
			{
				return a;
			}
			return b;	
		}	
		
		int getheight(Node * n)
		{
			if(n == NULL)
			{
				return 0;
			}
			
			return n->height;
		}

		int getbalancingfactor(Node * n)
		{
			if(n == NULL)
			{
				return 0;
			}

			return getheight(n->left) - getheight(n->right);
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

		Node * minValue(Node * n)
		{
			Node * curr = n;

			while(curr->left != NULL)
			{
				curr = curr->left;
			}
			return curr;
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
		
		    if(balance > 1 && getbalancingfactor(root->left) < 0)
			{
				root->left = rotateleft(root->left);
				return rotateright(root);
			}
		
		    if(balance < -1 && getbalancingfactor(root->right) > 0)
			{
				root->right = rotateright(root->right);
				return rotateleft(root);
			}
		
		    return root;
		}

		Node * deletenode(Node *& root, int data)
		{
			if(root == NULL)
			{
				return root;
			}

			if(data < root->data)
			{
				root->left = deletenode(root->left, data);
			}

			else if(data > root->data)
			{
				root->right = deletenode(root->right, data);
			}

			else if(data == root->data)
			{
				if(root->left == NULL || root->right == NULL)
				{
					Node * temp;

					if(root->left == NULL)
					{
						temp = root->left;
					}

					temp->right;

					if(temp == NULL)
					{
						temp = root;
						root = NULL;
					}
					else
					{
						*root = *temp;
						free(temp);
					}
				}
				else
				{
					Node * temp = minValue(root->right);

					root->data = temp->data;

					root->right = deletenode(root->right, temp->data);
				}
			}

			if(root == NULL)
			{
				return root;
			}

			root->height = max(getheight(root->left), getheight(root->right)) + 1;

			int balance = getbalancingfactor(root);

			if(balance > 1 && getbalancingfactor(root->left) >= 0)
			{
				return rotateright(root);
			}

			if(balance < -1 && getbalancingfactor(root->right) <= 0)
			{
				return rotateright(root);
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

	cout <<T->getheight(T->root) << endl;
    
	T->inorder(T->root);

	T->root = T->deletenode(T->root, 3);

	cout << endl;

	T->inorder(T->root);

} 