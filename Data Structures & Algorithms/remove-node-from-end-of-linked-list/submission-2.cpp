class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = getLinkedListSize(head);

        ListNode dummy(0);  
        dummy.next = head;
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

// fastをn個先に進める
        for (int i = 0; i <= n; i++) fast = fast->next;

// 同時に進める
        while (fast) {
        slow = slow->next;
        fast = fast->next;
        }

// slowが削除ノードの一つ前
        slow->next = slow->next->next;
        return dummy.next;
        }

private:    
    int getLinkedListSize(ListNode* head) {
        int count = 0;
        ListNode* current = head;
        while (current != nullptr) {
            count++;
            current = current->next; 
        }
        return count;
    }
};
