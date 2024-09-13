#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void add(string &num, int place){
        if(int(num.length())-place < 0){
            num = '1' + num;
            return;
        }
        int digit = stoi(to_string(num[num.length()-place] - '0'));
        digit++;
        if(digit>9){
            num[num.length()-place] = '0';
            add(num, place+1);
        } else{
            num[num.length()-place] = to_string(digit)[0]; 
        }
    }
    void subtract(string &num, int place){
        if(int(num.length())-place == 0 && num[0] == '1'){
            num = num.substr(1, num.length()-1);
            if(num.length() == 0){
                num = to_string(0);
            }
            return;
        }
        int digit = stoi(to_string(num[num.length()-place] - '0'));
        digit--;
        if(digit<0){
            num[num.length()-place] = '9';
            subtract(num, place+1);
        } else{
            num[num.length()-place] = to_string(digit)[0]; 
        }        
    }
    bool palindrome(string num){
        int start = 0;
        int end = num.length() - 1;
        while(start <= end){
            if(num[start++] != num[end--]) return false;
        }
        return true;
    }
    string nearestPalindromic(string n) {
        string incremental = n;
        add(incremental, 1);
        string decremental = n;
        subtract(decremental, 1);
        int up = 1;
        int down = 1;
        while(!palindrome(incremental)){
            add(incremental, 1);
            up++;
        }
        while(!palindrome(decremental)){
            subtract(decremental, 1);
            down++;
        }
        if(up<down) return incremental;
        return decremental;
    }
};