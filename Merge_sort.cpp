#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int start, int mid, int end){
    vector<int> arr1;
    vector<int> arr2;
    for(int i=start;i<mid;i++){
        arr1.push_back(arr[i]);
    }
    for(int i=mid;i<end;i++){
        arr2.push_back(arr[i]);
    }
    int i=0;
    int j=0;
    int p=start;
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i]>arr2[j]){
            arr[p++]=arr2[j++];
        }
        else{
            arr[p++]=arr1[i++];
        }
    }
    if(i==arr1.size()){
        while(j<arr2.size()){
            arr[p++]=arr2[j++];
        }
    }
    else{
        while(i<arr1.size()){
            arr[p++]=arr1[i++];
        }
    }
}

void merge_sort(vector<int> &arr,int start,int end){
    if(start<end){
        int middle=(start+end)/2;
        merge_sort(arr,start,middle);
        merge_sort(arr,middle,end);
        merge(arr,start,middle,end);
    }
}

int main(){
    vector<int> arr{34,12,32,23,1,2,5,8};
    merge_sort(arr,0,arr.size());
    for(int i:arr){
        cout<<i<<" ";
    }
}