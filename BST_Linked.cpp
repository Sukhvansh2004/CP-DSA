#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

void insertIntoBST(Node* &root,int d){
    //base case
    if(root == NULL){
        root=new Node(d);
    }

    else if(d>root->data){
        insertIntoBST(root->right,d);
    }
    else{
        insertIntoBST(root->left,d);
    }
}

void takeInput(Node* &root){
    int data;
    cin>>data;

    while(data !=-1){
        insertIntoBST(root,data);
        cin>>data;
    }
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp=q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
            continue;
        }
        cout<<temp->data<<" ";

        if(temp->left){ 
            q.push(temp->left);
        }
        
        if(temp->right){
            q.push(temp->right);
        }
    }

}

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* root){

    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int min(Node* root){
    if(root==NULL){
        return NULL;
    }
    while(root->left!=NULL){
        root=root->left;
    }
    return root->data;
}

int max(Node* root){
    if(root==NULL){
        return NULL;
    }
    while(root->right!=NULL){
        root=root->right;
    }
    return root->data;

}
Node* deleteFromBST(Node* root,int val){
    if(root==NULL)
        return root;
    if(root->data==val){
        // 0 Child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        //1 Child
        if(root->left==NULL && root->right!=NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        else if(root->left!=NULL && root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        //2 Child
        if(root->left != NULL && root->right != NULL){
            int mini=min(root->right);
            root->data=mini;
            root->right=deleteFromBST(root->right,mini );
            return root;
        }
    }
    else if(root->data>val){
        root->left=deleteFromBST(root->left,val);
        return root;
    }
    else{
        root->right=deleteFromBST(root->right,val);
        return root;
    }
}

int main(){
    Node* root=NULL;

    cout<<"Enter data to create BST "<<endl;
    takeInput(root);
    cout<<"Printing the BST"<<endl;
    levelOrderTraversal(root);

    cout<<endl<<"Printing inorder"<<endl;
    inorder(root);

    cout<<endl<<"Printing Post-order"<<endl;
    postorder(root);

    cout<<endl<<"Printing Pre-order"<<endl;
    preorder(root);

    int n;
    cout<<"Enter the value to be deleted: ";
    cin>>n;
    deleteFromBST(root,n);
    levelOrderTraversal(root);

    return 0;
}