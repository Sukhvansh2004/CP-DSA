#include <bits/stdc++.h>
using namespace std;
class MyStack {
public:
    queue<int> stack;
    MyStack() {
        
    }
    
    void push(int x) {
        stack.push(x);
    }
    
    int pop() {
        for(int i=0; i<stack.size()-1; i++){
            stack.push(stack.front());
            stack.pop();
        }
        int temp = stack.front();
        stack.pop();
        return temp;
    }
    
    int top() {
        for(int i=0; i<stack.size()-1; i++){
            stack.push(stack.front());
            stack.pop();
        }
        int temp = stack.front();
        stack.pop();
        stack.push(temp);
        return temp;
    }
    
    bool empty() {
        return stack.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->front();
 * bool param_4 = obj->empty();
 */