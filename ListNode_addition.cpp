#include <iostream>

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int i=0;
        ListNode* output;
        int prev_sum = 0;
        while(l1->next!=nullptr){
            output->val = (l1->val + l2->val + prev_sum)%10;
            prev_sum = (l1->val + l2->val + prev_sum)/10;
            output = output->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        return output;
    }
};