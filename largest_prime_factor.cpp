#include <iostream>
#include <cmath>
using namespace std;

bool prime(long long int n){
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

 long long int *pf(long long int n){
    long long int *array=new long long int[ int(floor(sqrt(n)))]{};
    long long int j=0;
    for(long long int i=1;i<=sqrt(n);i++){
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
    int y;
    cin>>y;
    for(int i=0;i<y;i++){
        long long int x;
        cin>>x;
        long long int *array=pf(x);
        long int a=array[0];
        for(long long int i=0;i<floor(sqrt(x));i++){
            if(array[i]!=0){
                if(array[i]>a){
                    a=array[i];
                }
            }
            else{
                break;
            }
        }
        cout<<a<<endl;

    }
}