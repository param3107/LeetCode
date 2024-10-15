

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *r = head, *l = head, *lprev = head;
        for(int i = 0; i < n; i++){
            r = r -> next;
            if(r == nullptr){
                head = head -> next;
                return head;
            }
        }
        while(r != nullptr){
            lprev = l;
            r = r -> next;
            l = l -> next;
        }
        lprev -> next = l -> next;
        return head;
    }
};  