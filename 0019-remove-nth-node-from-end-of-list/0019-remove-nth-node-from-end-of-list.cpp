/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* newhead = NULL;
        while (head != NULL) {
            ListNode* next = head->next;
            head->next = newhead;
            newhead = head;
            head = next;
        }
        return newhead;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return head; // Handle empty list case
        
        // Step 1: Reverse the list
        ListNode* reversedHead = reverseList(head);
        
        // Step 2: Remove the nth node from the front of the reversed list
        if (n == 1) {
            // Special case: removing the first node
            ListNode* newHead = reversedHead->next;
            delete reversedHead; // Free the memory of the removed node
            // Step 3: Reverse the list back to original
            return reverseList(newHead);
        }
        
        // General case: remove the nth node
        ListNode* temp = reversedHead;
        for (int i = 1; i < n - 1; ++i) {
            temp = temp->next;
        }
        
        // Now temp points to (n-1)th node, so remove temp->next (nth node)
        ListNode* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete; // Free the memory of the removed node
        
        // Step 3: Reverse the list back to original order
        return reverseList(reversedHead);
    }
};
