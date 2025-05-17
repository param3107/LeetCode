struct ListNode {     
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head -> next == nullptr) return head;
        int size = 0;
        ListNode* currNode = head, *lastNode = nullptr;
        while(true){
            size++;
            if(currNode -> next != nullptr) currNode = currNode -> next;
            else{
                currNode -> next = head;
                break;
            }
        }
        k %= size;
        currNode = head;
        int moves = size - k;
        for(int i = 0; i < moves-1; i++) currNode = currNode -> next;
        head = currNode -> next;
        currNode -> next = nullptr;
        return head;
    }
};