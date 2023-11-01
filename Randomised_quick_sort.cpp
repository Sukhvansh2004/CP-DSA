#include <iostream>
#include <random>
#include <vector>
#include <cmath>
using namespace std;

int partition(vector<int> &array, int start, int end, int rstart, int rend){
    random_device rd; 
    mt19937 gen(rd()); 

    uniform_int_distribution<> distribution(rstart, rend);

    int pivot = distribution(gen);
    swap(array[pivot], array[rend]);
    int p=rstart;

    for(int i=rstart;i<rend;i++){
        if(array[i]<array[end]){
            swap(array[p++],array[i]);
        }
    }

    swap(array[p],array[rend]);
    if((start+end)/2 - 1 <= p && p<=(start+end)/2 + 1){
        return p;
    }
    else if(p<(start+end)/2 - 1){
        return partition(array, start, end, p+1, rend);
    }
    else{
        return partition(array, start, end, rstart, p-1);
    }
        
}

void quick_sort(vector<int> &array,int start, int end, int &counter ){
    if(start<end){
        int p = partition(array, start, end, start, end);
        cout<<++counter<<endl;
        quick_sort(array, start, p-1, counter);
        cout<<counter<<endl;
        quick_sort(array, p+1, end, counter);
        cout<<--counter<<endl;
    }
}

int main(){
    
    int n;
    cin>>n;

    vector<int> array(n);

    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    int counter = 0;
    cout<<++counter<<endl;
    quick_sort(array, 0, array.size()-1, counter);
    cout<<--counter<<endl;

    for(int i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
}
