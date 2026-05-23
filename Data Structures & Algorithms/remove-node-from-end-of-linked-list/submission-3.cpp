class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        //先にn個だけ進めておく。
        for(int i=0;i<n;i++){
            fast = fast -> next;
        }
        if(!fast) return head -> next;
        ListNode* slow = head;
        while(fast -> next){
            fast = fast -> next;
            slow = slow -> next;
        }
        slow -> next = slow -> next -> next;
        return head;
    }
};
