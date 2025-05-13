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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, sum = 0;
        ListNode *start1 = l1, *start2 = l2;
        while(l1 != NULL && l2 != NULL){
            sum = l1 -> val + l2 -> val + carry;
            l1 -> val = sum % 10;
            l2 -> val = sum % 10;
            carry = sum/10;
            if(l1 -> next == NULL && l2 -> next == NULL){
                if(carry) l1 -> next = new ListNode(carry);
                return start1;
            }
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        while(l1 != NULL){
            sum = carry + l1 -> val;
            l1 -> val = sum%10;
            carry = sum/10;
            if(l1 -> next == NULL){
                if(carry > 0) l1 -> next = new ListNode(carry);
                return start1;
            }
            l1 = l1 -> next;
        }
        while(l2 != NULL){
            sum = carry + l2 -> val;
            l2 -> val = sum%10;
            carry = sum/10;
            if(l2 -> next == NULL){
                if(carry > 0) l2 -> next = new ListNode(carry);
                break;
            }
            l2 = l2 -> next;
        }
        return start2;
    }
};