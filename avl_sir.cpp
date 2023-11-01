#include<iostream>

using namespace std;

struct node
{
	int d;
	node *p;
	node *left;
	node *right;
	int h;
};

int height(node *);

int bf(node *root)
{
	if(root==NULL)
		return 0;
	return height(root->left)-height(root->right);
}

node* left(node *x)
{
	node *y=x->left;
	node *t=y->right;

	y->p=x->p;
	if (x->p != NULL)
	{
		if((x->p)->d>x->d)
			(x->p)->left=y;
		else
			(x->p)->right=y;
	}

	y->right=x;
	x->p=y;

	x->left=t;
	if(t!=NULL)
		t->p=x;
	x->h=std::max(height(x->left),height(x->right))+1;
	return y;
}

node* right(node *x)
{
        node *y=x->right;
        node *t=y->left;

        y->p=x->p;
        if (x->p != NULL)
        {
                if((x->p)->d>x->d)
                        (x->p)->left=y;
                else
                        (x->p)->right=y;
        }

        y->left=x;
        x->p=y;

        x->right=t;
        if(t!=NULL)
                t->p=x;
        x->h=std::max(height(x->left),height(x->right))+1;
        return y;
}


node* insert(node *root, node *temp)
{
	if(root==NULL)
	{
		temp->p=NULL;
		return temp;
	}
	if(temp->d < root->d)
	{
		node *ptr=insert(root->left, temp);
		ptr->p=root;
		if(root->h == ptr->h)
			root->h=(1+ptr->h);
		root->left=ptr;
	}
	else
	{
		node *ptr=insert(root->right, temp);
		ptr->p=root;
		if(root->h==ptr->h)
			root->h=(1+ptr->h);
		root->right=ptr;
	}
	if(bf(root)==2)
	{
		if (bf(root->left)==1)
			root=left(root);
		else
		{
			root->left=right(root->left);
			root=left(root);
		}
	}
	else if (bf(root)==-2)
	{
		if (bf(root->right)==-1)
			root=right(root);
		else
		{
			root->right=left(root->right);
			root=right(root);
		}
	}

	return root;
}

node* del(node *root, int key)
{
	if(root==NULL)
		return root;
	if(key<root->d)
        {
                root->left=del(root->left,key);

        }
        else if (key > root->d)
        {
                root->right=del(root->right,key);
        }
	else
	{
		if(root->left == NULL and root->right==NULL)
			return NULL;
		else if (root->left==NULL)
			return root->left;
		else if (root->right==NULL)
			return root->right;
		node *dptr=root->right;
		while(dptr->left!=NULL)
			dptr=dptr->left;
		root->d=dptr->d;
		root->right = del(root->right, dptr->d);
	}
	root->h=1+max(height(root->left),height(root->right));
	if(bf(root)==2)
        {
                if (bf(root->left)==1)
                        root=left(root);
                else
                {
                        root->left=right(root->left);
                        root=left(root);
                }
        }
        else if (bf(root)==-2)
        {
                if (bf(root->right)==-1)
                        root=right(root);
                else
                {
                        root->right=left(root->right);
                        root=right(root);
                }
        }
	return root;
}

int height(node *root)
{
	if(root==NULL)
		return 0;
	else
		return root->h;
}


void preorder(node *root)
{
	if(root!=NULL)
	{
		preorder(root->left);
		std::cout<< (root->d)<<"(h:"<<height(root)<<", bf:"<< bf(root)  <<") ";
		preorder(root->right);
	}
}


int main()
{
	int l=7;
	int a[l]={1,2,3,4,5,6,7};
	node *root=NULL;
	for(int i=0;i<l;i++)
	{
	        node *temp=new node();
	        temp->d=a[i];
	        temp->left=NULL;
	        temp->right=NULL;
		temp->h=1;
		root = insert(root, temp);
	}

	preorder(root);
	std::cout<<std::endl;
	root=del(root,9);
	root=del(root,8);
	root=del(root,12);
	root=del(root,5);
	root=del(root,4);
	preorder(root);
        std::cout<<std::endl;
	return 0;
}

