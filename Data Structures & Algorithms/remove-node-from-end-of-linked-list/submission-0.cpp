class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = getLinkedListSize(head);
    
        ListNode* dummy = new ListNode(0, head);
        ListNode* current = dummy;
        
        for (int i = 0; i < sz - n; i++) {
            current = current->next;
        }
        
        // Step 1: Save the target node to a temporary pointer
        ListNode* nodeToDelete = current->next;
        
        // Step 2: Skip the target node in the chain
        current->next = current->next->next;
        
        // Step 3: Safely delete the isolated node from memory
        delete nodeToDelete;
        
        // Step 4: Save the real head, delete dummy, and return
        ListNode* newHead = dummy->next;
        delete dummy; 
        return newHead;
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
