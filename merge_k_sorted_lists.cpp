#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
struct Comp{
    bool operator()(pair<ListNode*,int> a, pair<ListNode*,int> b){
        return a.first->val>b.first->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<ListNode*, int>, vector<pair<ListNode*, int>>, Comp> pq; 
        for(int i=0;i<lists.size();i++){
            if(lists[i] != nullptr){
                pair<ListNode*,  int> node;
                node.first = lists[i];
                node.second = i;
                pq.push(node);
            }
        }
        ListNode* result(nullptr);
        ListNode* head(result);
        while(!pq.empty()){
            pair<ListNode*, int> node;
            node = pq.top();
            ListNode* newNode = new ListNode(node.first->val);
            head = newNode;
            head = head->next;
            pq.pop();
            int index = node.second;
            lists[index] = lists[index]->next;
            if(lists[index] != nullptr){
                pair<ListNode*, int> point;
                point.first = lists[index];
                point.second = index;
                pq.push(point);
            }
        }
        return result;
    }
};