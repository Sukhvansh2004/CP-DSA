#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void radix_sort(vector<int> &arr, int n){
    int max = arr[0];
    int min=arr[0];

    for(int i=0; i<n; i++){
        if(min>arr[i]){
            min=arr[i];
        }
    }
    if(min<0){
        for(int i=0; i<n; i++){
            arr[i] = arr[i] - min;
        }
    }
    for(int i=0; i<n; i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    int j=1;
    while(int(max/(pow(10, j))) != 0){
        j++;
    }
    
    for(int l=1;l<=j;l++){
        vector<int> element(n);
        int k = pow(10, l);
        for(int i=0;i<n;i++){
            element[i] = (arr[i] % k)/(k/10);
        }
        vector<int> index(10);
        for(int i=0; i<n; i++){
            index[element[i]]++;
        }
        for(int i=1; i<10; i++){
            index[i] = index[i] + index[i-1];
        }
        vector<int> sorted(n);
        
        for(int i=n-1;i>=0;i--){
            sorted[--index[element[i]]] = arr[i];
        }
        arr = sorted;
    }

    if(min<0){
        for(int i=0;i<n;i++){
            arr[i] = arr[i] + min;
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    radix_sort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
