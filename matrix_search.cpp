#include <iostream>
#include <vector>
using namespace std;

int search(vector<vector<int>> matrix, int key){
    int m = matrix.size();
    int n = matrix[0].size();

    int i = 0;
    int j = n-1;

    while(i<m && j>=0){
        if(matrix[i][j]==key){
            return n*i + j+1;
        }
        else if(matrix[i][j]<key){
            i++;
        }
        else if(matrix[i][j]>key){
            j--;
        }
    }
    return -1;
}

int main() {
    int rows = 15;
    int cols = 20;

    vector<vector<int>> matrix(15, vector<int>(20, 0));
    
    int value = 1;
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = value++;
        }
    }

    int n;
    cin>>n;

    cout<<search(matrix, n);

}
