#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseParentheses(string s) {
        vector<int> open;
        vector<int> close;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(')
                open.push_back(i);
            else if (s[i] == ')')
                close.push_back(i);
        }

        int n = open.size();
        int start = open.size() - 1;
        int end = 0;
        string result = "";
        if(n == 0) return s;
        while (n > 0) {
            if (n % 2 == 1) {
                if (start == open.size() - 1) {
                    for (int it = close[end] - 1; it >= open[start] + 1; it--) {
                        result += s[it];
                    }
                } else {
                    string front = s.substr(close[end-1] + 1, close[end] - close[end-1] - 1);
                    string back = s.substr(open[start] + 1, open[start+1] - open[start] - 1);
                    reverse(back.begin(), back.end());
                    reverse(front.begin(), front.end());
                    result = front + result + back;
                }
            } else {
                if (start == open.size() - 1) {
                    for (int it = open[start] + 1; it <= close[end] - 1; it++) {
                        result += s[it];
                    }
                } else {
                    string back = s.substr(close[end-1] + 1, close[end] - close[end-1] - 1);
                    string front = s.substr(open[start] + 1, open[start+1] - open[start] - 1);
                    result = front + result + back;
                }
            }
            n--;
            start--;
            end++;
        }
        if(open[0] != 0) result = s.substr(0, open[0]) + result;
        if(close.back() != s.length() - 1) result = result + s.substr(close.back() + 1, s.length() - close.back() - 1);
        return result;
    }
};