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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1) return head;
        ListNode headNode = ListNode(0, head);
        ListNode *headHolder = &headNode;
        ListNode *currHead = headHolder, *first = head, *last = head, *next = head, *currNode = nullptr, *temp = nullptr, *prevNode = nullptr;
        while(true){
            for(int i = 1; i < k; i++){
                last = last -> next;
                if(last == nullptr){
                    currHead -> next = first;
                    return headHolder -> next;
                }
            }
            currHead -> next = last;
            next = last -> next;
            currNode = first;
            int rvrs = k;
            prevNode = nullptr;
            while(rvrs--){
                temp = currNode -> next;
                currNode -> next = prevNode;
                prevNode =  currNode;
                currNode = temp;
            }
            currHead = first;
            first = next;
            last = next;
            if(first == nullptr) break;
        }
        return headHolder -> next;
    }
};