#include <iostream>
#include <chrono>
using namespace std;

int main(){
    cout<<"Enter the first no. : ";
    int x;
    cin>>x;
    cout<<"Enter the second number : ";
    int y;
    cin>>y;
    //Using Factors 
    auto s1=chrono::high_resolution_clock::now();
    int *a1=new int[x]{};
    int *a2=new int[y]{};
    int j1(0), j2(0);
    for(int i=1;i<=x;i++){
        if(x%i==0){
            cout<<j1<<' ';
            a1[j1++]=i;
        }
    }
    for(int i=1;i<=y;i++){
        if(y%i==0){
            a2[j2++]=i;
        }
    }
    j1--;
    j2--;
    while(true){
        if(a1[j1]>a2[j2]){
            j1--;
        }
        else if(a1[j1]<a2[j2]){
            j2--;
        }
        else{
            cout<<"The GCD(using factors) is : "<<a1[j1]<<endl;
            break;
        }
    }
    auto e1=chrono::high_resolution_clock::now();


    int x1=x;
    int y1=y;

    //Using Euclidean Algorithm

    auto s2=chrono::high_resolution_clock::now();    
    while(true){
        if(x1>y1){
            x1=x1%y1;
            if(x1 == 0) break;
        }
        else{
            y1=y1%x1;
            if(y1 ==0) break;
        }
    }
    cout<<"The GCD (using Euclidean Algorithm) is : "<<max(x1,y1)<<endl;
    auto e2=chrono::high_resolution_clock::now();

cout<<endl;
cout<<"The duration using factors is "<<chrono::duration_cast<chrono::microseconds>(e1-s1).count()<<" microseconds"<<endl;
cout<<"The duration using Euclidean Algorithm is "<<chrono::duration_cast<chrono::microseconds>(e2-s2).count()<<" microseconds"<<endl;
cout<<endl;
}