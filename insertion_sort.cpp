#include <iostream>
using namespace std;

int main(){
    cout<<"Enter the number of elements in the array : ";
    int x;
    int c=0;
    int s=0;
    cin>> x;
    int *a=new int[x]{};
    for(int i=0;i<x;i++){
        cout<<"Enter the "<<i+1<<"th number"<<endl;
        cin>>a[i];
    }
    for(int j=1;j<x;j++){
        while(j>0){
            c++;
            if(a[j]<a[j-1]){
                int t=a[j];
                a[j]=a[j-1];
                a[j-1]=t;
                j--;
                c++;
                s++;
            }
            else{
                break;
            }
        }
    }
    cout<<"The sorted array is ";
    for(int i=0;i<x;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<"The number of comparisons are "<<c<<" and the number of swaps are "<<s<<endl;
}
