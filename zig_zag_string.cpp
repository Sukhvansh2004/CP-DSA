#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows != 1){
            int mat = 2 * (numRows - 1);
            vector<string> matrix(mat);
            for(int i=0;i<mat;i++){
                int index = 0;
                for(int j=i;j<s.length();j=2*(numRows) -2 + j){
                    matrix[i] += s[j];
                }
            }
            string result = "";
            for(int i=0;i<numRows;i++){
                if(i != 0 && i != numRows - 1 ){
                    bool state = 0;
                    int first = 0;
                    int second = 0;
                    int index = 2*(numRows-1) - i;
                    while(true){
                        if(state==0 && first<matrix[i].length()){
                            result = result + matrix[i][first++];
                        }
                        else if(state==1 && second<matrix[index].length()){
                            result = result + matrix[index][second++];
                        }
                        state = !state;
                        if((second >= matrix[index].length()) && (first >= matrix[i].length())){
                            break;
                        }
                    }
                }
                else{
                    result += matrix[i];
                }
            }
            
            return result;
        }
        else{
            return s;
        }
    }
};