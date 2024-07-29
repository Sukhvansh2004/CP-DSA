#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> rows;
        unordered_set<int> cols;

        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[i].size(); j++){
                if(matrix[i][j] == 0){
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        for(const int &i: rows){
            for(int j=0; j<matrix[i].size(); j++){
                matrix[i][j] = 0;
            }
        }
        for(const int &j: cols){
            for(int i=0; j<matrix.size(); i++){
                matrix[i][j] = 0;
            }
        }
    }
};

int main(){
    Solution s;
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    s.setZeroes(matrix);
    return 0;
}