#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int pointer = 0;
        vector<string> words;
        for(int i=0;i<s.length();i++){
            if(s[i] == ' '){
                if(i-pointer > 1 || (pointer == 0 && i == 1)){
                    words.push_back(s.substr(pointer, i - pointer));
                }
                pointer = i;
            }
        }
        if(pointer != s.length()-1){
            words.push_back(s.substr(pointer, s.length() - pointer));
        }
        string result;
        for(int i=words.size()-2; i>=1; i--){
            result += words[i];
        }
    
        if(words[0][0] == ' '){
            result += words[0];
        }
        else{
            result += ' ' + words[0];
        }

        if(words.size() != 1){
            if(words[words.size()-1][0] == ' '){
                result = words[words.size()-1].substr(1, words[words.size()-1].length() - 1) + result;
            }
        }
        return result;
    }
};