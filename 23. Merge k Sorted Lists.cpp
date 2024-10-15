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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;  
        ListNode *newHead = (list1 -> val < list2 -> val) ? list1 : list2, *temp = nullptr;
        ListNode *currHead = newHead, *p1 = list1, *p2 = list2;
        while(p1 && p2){
            if(p1 -> val < p2 -> val){
                temp = p1 -> next;
                currHead -> next = p1;
                p1 = temp;
            }
            else{
                temp = p2 -> next;
                currHead -> next = p2;
                p2 = temp;
            }
            currHead = currHead -> next;
        }
        while(p1){
            currHead -> next = p1;
            p1 = p1 -> next;
            currHead = currHead -> next;
        }
        while(p2){
            currHead -> next = p2;
            p2 = p2 -> next;
            currHead = currHead -> next;
        }
        return newHead;
    }

    ListNode* mergeSortLinkedLists(vector<ListNode*>& lists, int l, int r){
        if(r == l) return lists[r];
        if(r - l == 1) {
            return mergeTwoLists(lists[l], lists[r]);
        }
        ListNode *l1 = mergeSortLinkedLists(lists, l, (l + r)/2);
        ListNode *l2 = mergeSortLinkedLists(lists, (l + r)/2 + 1, r);
        return mergeTwoLists(l1, l2);
    }


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = nullptr;
        if(lists.size() == 0) return head;
        int r = lists.size() - 1, l = 0;
        head = mergeSortLinkedLists(lists, l, r);   
        return head;     
    }
};

