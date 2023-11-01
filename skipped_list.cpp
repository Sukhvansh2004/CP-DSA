#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node* prev;

    node(int data = 0) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class skip {
public:
    node* val;
    skip* next;
    skip* prev;
    int gap = 0;

    skip(node* val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

skip* list() {
    node* head = new node();
    int n;
    cout << "Enter the number of elements you want to enter in the list: ";
    cin >> n;
    node* temp = head;
    for (int i = 1; i < n; i++) {
        cin >> temp->data;
        temp->next = new node();
        temp->next->prev = temp;
        temp = temp->next;
    }
    cin >> temp->data;
    node* t2 = head;
    for (int i = 2; i <= n; i++) {
        int j = i;
        t2 = t2->next;
        temp = t2;
        while (j > 1) {
            if (temp->data < temp->prev->data) {
                node* t = temp->prev;
                if (t->prev == NULL) {
                    t->next = temp->next;
                    temp->next = t;
                    t->next->prev = t;
                    temp->prev = NULL;
                    t->prev = temp;
                }
                else {
                    t->next = temp->next;
                    temp->next->prev = t;
                    t->prev->next = temp;
                    temp->next = t;
                    temp->prev = t->prev;
                    t->prev = temp;
                }
            }
            else {
                break;
            }
            j--;
        }
    }
    cout << "Enter the gap: ";
    int k;
    cin >> k;
    skip* s = new skip(head);
    skip* l = s;
    l->gap = k;
    int count = l->gap;
    temp = head;
    for (int i = 1; i <= n; i++) {
        temp = temp->next;
        if (count == 0) {
            l->next = new skip(temp);
            l->next->prev = l;
            l = l->next;
            count = l->gap;
        }
        count--;
    }
    return s;
}


void search(skip* &a,int v){
    skip* t=a;
    int count=0;
    while(true){
        if(t->val->data==v){
            cout<<"The element occurs at: "<<count+1<<endl;
            return;
        }
        else if(t->val->data<v){
            if(t->next!=NULL){
                t=t->next;
                count=count+t->gap+1;
            }
            else{
                break;
            }
        }
        else if(t->val->data>v){
            t=t->prev;
            break;
        }
    }
    node* start=t->val;
    for(int i=1;i<=t->gap;i++){
        if(v==start->data){
            cout<<"The element occurs at: "<<count+1;
            return;
        }
        else{
            if(start->next!=NULL){
                start=start->next;
                count++;
            }
            else{
                cout<<"The element is'nt present in the list "<<endl;
                return;
            }
        }
    }

}

int main(){
skip* a=list();
cout<<endl<<"Enter the value to be searched: ";
int z;
cin>>z;
search(a,z);
}