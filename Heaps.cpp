#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class heap {
    public:

    vector<int> list;
    int heap_size;

    heap(){
        this->heap_size=0;
    }
    int left(int i){
        return 2*i+1;
    }

    int right(int i){
        return 2*i+2;
    }

    int parent(int i){
        return ceil(float(i)/2.0)-1;
    }

    void heapify(int i){
        int largest=i;
        if(left(i)<heap_size && list[left(i)]>list[largest]){
            largest=left(i);
        }
        if(right(i)<heap_size && list[right(i)]>list[largest]){
            largest=right(i);
        }
        if(largest!=i){
            swap(list[i],list[largest]);
            heapify(largest);
        }
    }

    void increase_key(int index,int key){
        if(index>=heap_size){
            cout<<"Index out of bounds"<<endl;
            return;
        }
        if(key<list[index]){
            cout<<"Key smaller than current value"<<endl;
            return;
        }
        list[index]=key;
        while(index>0 && list[index]>list[parent(index)]){
            swap(list[index],list[parent(index)]);
            index=parent(index);
        }
    }
    void insert_key(int i){
        this->heap_size+=1;
        list.push_back(INT_MIN);
        increase_key(heap_size-1,i);   
    }

    void build(int *l,int n){
        for(int i=0;i<n;i++){
            list.push_back(l[i]);
        }
        this->heap_size=n;
        for(int i=floor(heap_size/2);i>=0;i--){
            heapify(i);
        }  
    }

    vector<int> heap_sort(){
        vector<int> temp=list;
        int t=heap_size;
        for(int i=heap_size-1;i>0;i--){
            swap(list[0],list[i]);
            heap_size--;
            heapify(0);
        }
        this->heap_size=t;
        vector<int> r=list;
        list=temp;
        return r;
    }

    int max(){
        if(heap_size!=0){
            return list[0];
        }
        else{
            cout<<"Heap is empty"<<endl;
            return 0;
        }
    }

    int extract_max(){
        this->heap_size--;
        swap(list[0],list[heap_size]);
        heapify(0);
        return list[heap_size];
    }
};

int main(){
    int *l=new int[10]{2,23,12,42,45,56,51,21,10,50};
    heap* h=new heap();
    h->build(l,10);
    vector<int> s=h->heap_sort();
    for(int i=0;i<10;i++){
        cout<<s[i]<<endl;
    }
}