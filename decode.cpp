#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool isStringDigit(char& c) {
        if (!isdigit(static_cast<unsigned char>(c))) return false;
        return true;
    }

    string decodeString(string s) {
        string num = "";
        bool state = true;
        string result = "";
        string rep = "";
        int k = 0;
        for(int i=0; i<s.length(); i++){
            if(state && isStringDigit(s[i])){
                num += s[i];
            }
            else{
                if(s[i] == '['){
                    rep = "";
                    k = stoi(num);
                    state = false;
                }
                else if(s[i] == ']'){
                    for(int i=0; i<k; i++){
                        result += rep;
                    }
                    state = true;
                    num = "";

                }
                else{
                    rep += s[i];
                }
            }
        }
        return result;
    }
};