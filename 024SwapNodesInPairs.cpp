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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr) return head;
        if(head -> next == nullptr) return head;
        ListNode *temp1 = head, *temp2 = head -> next -> next, *temp3 = nullptr ;
        head -> next -> next = head;
        head = head -> next;
        while(true){
            if(temp2 == nullptr){
                temp1 -> next = temp2;
                break;
            }
            if(temp2 -> next == nullptr){
                temp1 -> next = temp2;
                break;
            }
            temp1 -> next = temp2 -> next;
            temp1 = temp1 -> next;
            temp3 = temp1 -> next;
            temp1 -> next = temp2;
            temp2 = temp3;
            temp1 = temp1 -> next;
        }
        return head;
    }
};