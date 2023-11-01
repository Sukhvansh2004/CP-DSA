#include <iostream>
#include <cstring>

using namespace std;

int main(){
    string in;
    cin>>in;
    char *a=new char[size(in)]{};
    int n=size(in);
    for(int i=0;i<n;i++){
        a[i]=in[i];
    }
    string t="";
    for(int i=n-2;i<n;i++){
        t=t+a[i];
    }
    a[(n-1)]=' ';
    a[(n-2)]=' ';
    a[n]=' ';

    if(t=="PM"){
        int tn =10*((a[0])-48)+((a[1])-48);
        if(tn!=12){
            tn=tn+12;
            int c1=48;
            while(tn/10>0){
                c1++;
                tn=tn-10;
            }
            int c2=48+tn;
            a[0]=char(c1);
            a[1]=char(c2);
        }
        
    }
    if(t=="AM"){
        int tn =10*((a[0])-48)+((a[1])-48);
        if(tn==12){
            a[0]='0';
            a[1]='0';
        }
    }

    cout<<a;
    }
