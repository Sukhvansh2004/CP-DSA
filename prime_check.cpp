#include <iostream>
#include <cmath>
#include <chrono>
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
    cout<<"Enter a Number : ";
    cin>>x;
    //Checking (1,N) {Brute Force}
    cout<<"Factorization using Brute force"<<endl;
    auto s1=chrono::high_resolution_clock::now();
    int *array1=new int[x]{};
    int j=0;
    for(int i=1;i<=x;i++){
        if(x%i==0){
            array1[j]=i;
            j++;
        }
    }
    auto e1=chrono::high_resolution_clock::now();
    cout<<"Factors of "<<x<<" are : "<<endl;
    for(int i=0;i<j;i++){
        cout<<array1[i]<<endl;
    }
    cout<<endl;
    delete array1;
    array1=nullptr;
    cout<<"The time taken is "<<chrono::duration_cast<chrono::microseconds>(e1-s1).count()<<" microseconds"<<endl<<endl;

    //Checking(1,sqrt(N)) 

    cout<<"Factorization using (1,Sqrt(N)) is "<<endl;
    auto s2=chrono::high_resolution_clock::now();
    int *array2=new int[x]{};
    int k=0;
    const int root=sqrt(x);
    for(int i=1;i<=root;i++){
        if(x%i==0){
            array2[k++]=i;
            if(i!=root){
                array2[k++]=x/i;
            }
        }
    }
    auto e2=chrono::high_resolution_clock::now();
    cout<<"Factors of "<<x<<" are : "<<endl;
    for(int i=0;i<k;i++){
        cout<<array2[i]<<endl;
    }
    cout<<endl;
    delete array2;
    array2=nullptr;
    cout<<"The time taken is "<<chrono::duration_cast<chrono::microseconds>(e2-s2).count()<<" microseconds"<<endl<<endl;

    //Using Prime Factors

    cout<<"Prime factorization "<<endl;
    auto s3=chrono::high_resolution_clock::now();
    int *array=pf(x);
    auto e3=chrono::high_resolution_clock::now();
    cout<<"Prime Factors of "<<x<<" are : "<<endl;
    for(int i=0;i<=sqrt(x);i++){
        if(array[i]!=0){
            cout<<array[i]<<endl;
        }
    }
    cout<<"The time taken is "<<chrono::duration_cast<chrono::microseconds>(e3-s3).count()<<" microseconds"<<endl<<endl;
    

}