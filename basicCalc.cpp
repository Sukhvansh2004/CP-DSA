#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void ops(stack<string> &s1, stack<string> &s2, string op){
        // cout<<s1.size()<<"-------"<<endl;
        while(s1.size() > 0){
            cout<<s1.top()<<endl;
            if(s1.top() == op){
                float b = stof(s2.top());
                s2.pop();
                s1.pop();
                float a = stof(s1.top());
                s1.pop();
                string c;
                if (op == "/") {
                    c = to_string(b / a);
                } else if (op == "*") {
                    c = to_string(a * b);
                } else if (op == "+") {
                    c = to_string(a + b);
                }
                s2.push(c);
            } else{
                s2.push(s1.top());
                s1.pop();
            }
        }
        cout<<"----------"<<s1.size()<<"----"<<s2.size()<<endl;
    }
    int calculate(string s) {
        stack<string> s1;
        stack<string> s2;
        string digit;
        s += ' ';
        for(int i=0; i<s.length(); i++){
            if(isdigit(s[i])){
                digit += s[i];
            }
            else{
                if(digit.length() > 0)
                    s1.push(digit);
                digit = "";
                if(s[i] == '-'){
                    digit += s[i];
                    string oper = "+";
                    s1.push(oper);
                }
                else if(s[i] == '+' || s[i] == '*' || s[i] == '/'){
                    string oper;
                    oper += s[i];
                    s1.push(oper);
                }
            }
        }
        ops(s1, s2, "");
        ops(s2, s1, "/");
        ops(s1, s2, "*");
        ops(s2, s1, "+");
        // ops(s2, s1, "+");
        return stoi(s1.top());
    }
};