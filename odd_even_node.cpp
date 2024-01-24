#include <bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head){
            return head;
        }
        ListNode* connect = head;
        while(connect->next){
            connect = connect->next;
        }
        ListNode* last = connect;
        while(head->val%2 == 0){
            ListNode* temp = head;
            head = head->next;
            last->next = temp;
            temp->next = nullptr;
            last = last->next;
        }
        ListNode* temp = head;
        while(temp != connect){
            if(temp->next->val%2 == 0){
                ListNode* tmp = temp->next;
                temp->next = tmp->next;
                last->next = tmp;
                tmp->next = nullptr;
                last = last->next;
            }
            temp = temp->next;
        }
        return head;
    }
};