#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct node{
	int data;
	struct node *left, *right;
} tree;

tree *root, *ptr;
int op, item; 

tree *create(int x)
{
	tree *temp;
	temp = new tree;
 	temp->data=x;
 	temp->left=NULL;
 	temp->right=NULL;
	return (temp);
}

tree *insert(tree *node, int key)
{
	if(node==NULL)
		return create(key);
	
	if(key<node->data) 
        node->left=insert(node->left,key); 
    else if(key>node->data) 
        node->right=insert(node->right, key);
    return node;  
}

void inorder(tree *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        cout<<root->data<<endl; 
        inorder(root->right); 
    } 
} 

void preorder(tree *root) 
{ 
    if (root != NULL) 
    { 
        cout<<root->data<<endl;
        preorder(root->left);  
        preorder(root->right); 
    } 
} 

void postorder(tree *root) 
{ 
    if (root != NULL) 
    { 
        postorder(root->left);  
        postorder(root->right); 
        cout<<root->data<<endl;
    } 
} 

int main()
{
	root = NULL;

		cout<<"1. Create \n";
		cout<<"2. Insert \n";
		cout<<"3. Inorder Traversal \n";
		cout<<"4. Preorder Traversal \n";
		cout<<"5. Postorder Traversal \n";
		do{
		cout<<"\n Choose your option: ";
		cin>>op;
		switch(op)
		{
			case 1:
				{
					cout<<"ENter Value: ";
					cin>>item;
					root = insert(root,item);
				}
				break;
			case 2:
				{
					cout<<"ENter Value: ";
					cin>>item;
					insert(root,item);
				}
				break;
			case 3:
				{
					inorder(root);
				}
				break;
			case 4:
				{
					preorder(root);
				}
				break;
			case 5:
				{
					postorder(root);
				}
				break;
			
		}
	}while(op!=6);
	return 0;
}

