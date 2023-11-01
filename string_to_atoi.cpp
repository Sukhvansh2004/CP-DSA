#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        int start = -1;
        int end = -1;
        for(int i=0;i<s.length();i++){
            if((s[i]=='-') && (start==-1)){
                sign = -1;
            }
            else if((int(s[i])>=48 && int(s[i])<=57) && (start==-1)){
                start = i;
            } 
            else if(!(int(s[i])>=48 && int(s[i])<=57) && (end==-1) && (start!=-1)){
                end = i;
                i = s.length();
            }
        }
        if(end==-1) end=s.length();
        int num_chars = end-start;
        int result = 0;
        for(int i=0;i<num_chars;i++){
            result += pow(10, i) * (int(s[end-i-1])-48);
        }
        result *= sign;
        return result;
    }
};