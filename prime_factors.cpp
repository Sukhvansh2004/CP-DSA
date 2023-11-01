#include <iostream>
#include <cmath>
using namespace std;

bool prime(int n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int *pf(int n){
    int *array=new int[n]{};
    int j=0;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            if(prime(i)){
                array[j]=i;
                j++;
            }
            if(prime(n/i)){
                array[j]=n/i;
                j++;
            }
        }
    }
    return array;
}

int main(){
    int x;
    cout<<"Enter the number"<<endl;
    cin>>x;
    int *array=pf(x);
    for(int i=0;i<=sqrt(x);i++){
        if(array[i]!=0){
            cout<<array[i]<<endl;
        }
    }

}

