#include <iostream>
using namespace std;

class array{
    public:
    int* a;
    int size;

    array(){
        this->a=new int[1]{};
        this->size=1;
    }

    void resize(){
        int*t =new int[size*2]{};
        for(int i=0;i<size;i++){
            t[i]=a[i];
        }
        delete a;
        this->a=t;
        this->size=size*2;
    }
    
    void insert(int d,int p){
        if(p<size){
            a[p]=d;
        }
        else{
            this->resize();
            this->insert(d,p);
        }

    }

};

array* build(array* p,int k=0){
    if(p==NULL){
        p=new array();
        cout<<"Enter the root data: ";
        int n;
        cin>>n;
        p->insert(n,k);
        cout<<"Enter the data to the left of "<<n<<": ";
        p=build(p,2*k+1);
        cout<<"Enter the data to the right of "<<n<<": ";
        p=build(p,2*k+2);
        return p;
    }
    int n;
    cin>>n;
    if(n!=0){
        p->insert(n,k);
        cout<<"Enter the data to the left of "<<n<<": ";
        p=build(p,2*k+1);
        cout<<"Enter the data to the right of "<<n<<": ";
        p=build(p,2*k+2);
        return p;
    }
    return p;
}

array* input(array* root,int t,int k=0){
    if(root==NULL){
        return build(root);
    }
    if(k<root->size){
        int n=root->a[k];
        if(n!=0){
            cout<<"Press 1 for going left and any other no. for going right :";
            int d;
            cin>>d;
            if(d==1){
                return input(root,2*k+1,t);
            }
            else{
                return input(root,2*k+1,t);
            }
        }
        else{
            root->insert(t,k);
            return root;
        }
    }
    else{
        root->insert(t,k);
        return root;
    }
}

int search(array* root,int t,int k=0){
    if(root==NULL){
        return -1;
    }
    if(k<root->size){
        int n=search(root,t,2*k+1);
        if(n!=-1){
            return n;
        }
        if(t==root->a[k]){
            return k;
        }
        int n1=search(root,t,2*k+2);
        if(n1!=-1){
            return n1;
        }
    }
    return -1;
}

array* del(array* root,int d,int t=0){
    if(t==0){
        t=search(root,d);
    }
    if(t==-1){
        cout<<"Element not found in the Binary Tree";
        return root;
    }
    if(2*t+1<root->size && 2*t+2<root->size){
        if(root->a[2*t+2]!=0){
            root->a[t]=root->a[2*t+2];
            return del(root,d,2*t+2);
        }
        else if(root->a[2*t+1]!=0){
            root->a[t]=root->a[2*t+1];
            return del(root,d,2*t+1);
        }
        else{
            root->a[t]=0;
            return root;
        }
    }
    else if(2*t+1<root->size){
        if(root->a[2*t+1]!=0){
            root->a[t]=root->a[2*t+1];
            return del(root,d,2*t+1);
        }
        else{
            root->a[t]=0;
            return root;
        }
    }
    else if(2*t+2<root->size){
        if(root->a[2*t+2]!=0){
            root->a[t]=root->a[2*t+2];
            return del(root,d,2*t+2);
        }
        else{
            root->a[t]=0;
            return root;
        }
    }
    else{
        root->a[t]=0;
        return root;       
    }
}

int main(){
    array* root;
    root=build(root);
    while (true){
        cout<<endl<<"Press 1 for insertion, 2 for deletion and 3 for search ";
        int c;
        cin>>c;
        if(c==1){
            cout<<"Input the value: ";
            int t;
            cin>>t;
            root=input(root,t);
        }
        else if(c==2){
            cout<<"Input the value to be deleted: ";
            int t;
            cin>>t;
            root=del(root,t);
        }
        else if(c==3){
            cout<<"Input the value to be searched: ";
            int t;
            cin>>t;
            int p=search(root,t);
            if(p==-1){
                cout<<"The element is not in the tree"<<endl;
            }
            else{
                cout<<"The element is present at the "<<p<<" index"<<endl;
            }
        }
        else{
            break;
        }
    }
    for(int i=0;i<root->size;i++){
        cout<<root->a[i]<<" ";
    }
}