#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int partition(vector<float> &arr,int start,int end){
    float pivot=arr[end];
    int j=start;
    for(int i=start;i<=end;i++){
        if(arr[i]<pivot){
            swap(arr[i],arr[j++]);
        }
    }
    swap(arr[j],arr[end]);
    return j;
}

void quick_sort(vector<float> &arr,int start,int end){
    if(start<end){
        int pivot=partition(arr,start,end);
        quick_sort(arr,start,pivot-1);
        quick_sort(arr,pivot+1,end);
    }
}


vector<float> bucket_sort(vector<float> arr){
    vector<vector<float>> temp(arr.size());
    for(float i : arr ){
        temp[int(floor(i*arr.size()))].push_back(i);
    }
    vector<float> r;
    for(vector<float> i:temp){
        quick_sort(i,0,i.size()-1);
        for(float j:i){
            r.push_back(j);
        }
    }
    return r;
}

int main(){
    vector<float> arr{0.32,0.5,0.01,0.34,0.85,0.12,0.02};
    arr=bucket_sort(arr);
    for(float i:arr){
        cout<<i<<" ";
    }
}