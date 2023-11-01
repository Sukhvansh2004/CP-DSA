#include <iostream>
using namespace std;

void mul(int a[3][3],int b[3][3]){
    int prod[3][3]={};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int sum=0;
            for(int l=0;l<3;l++){
                sum=sum+a[i][l]*b[l][j];
            }
            prod[i][j]=sum;
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<prod[i][j]<<" ";
        }
        cout<<endl;
    }
}


int main(){
    int mat1[3][3]={{1,4,7},{2,5,8},{3,6,9}};
    int mat2[3][3]={{1,4,7},{2,5,8},{3,6,9}};

    mul(mat1,mat2);

}