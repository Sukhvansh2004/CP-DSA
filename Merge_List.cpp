#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class heap{

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
        int smallest=i;
        if(left(i)<heap_size && list[left(i)]<list[smallest]){
            smallest=left(i);
        }
        if(right(i)<heap_size && list[right(i)]<list[smallest]){
            smallest=right(i);
        }
        if(smallest!=i){
            swap(list[i],list[smallest]);
            heapify(smallest);
        }
    }

    void build(vector<int> l){
        list=l;
        this->heap_size=l.size();
        for(int i=list.size()/2;i>=0;i--){
            heapify(i);
        }
    }

    int min(){
        int t=list[0];
        this->heap_size--;
        list[0]=list[heap_size];
        list.pop_back();
        heapify(0);
        return t;
    }

};

vector<int> merge(vector<vector<int>> l){
    int max=0;
    for(int i=0;i<l.size();i++){
         max>l[i].size() ? max=max : max=l[i].size();
    }
    vector<int> a;
    for(int i=0;i<max;i++){
        for(int j=0;j<l.size();j++){
            if (i<l[j].size()){
                a.push_back(l[j][i]);
            }
        }
    }
    heap t;
    vector<int> result;
    t.build(a);
    while(t.heap_size>0){
        result.push_back(t.min());
    }
    return result;
}

int main(){
    vector<vector<int>> l={{1,2,3},{4,5,6},{7,8,9}};
    vector<int> r=merge(l);
    for(int i=0;i<r.size();i++){
        cout<<r[i]<<" ";
    }
}