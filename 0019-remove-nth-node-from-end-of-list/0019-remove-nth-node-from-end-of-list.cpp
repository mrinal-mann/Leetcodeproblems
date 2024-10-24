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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) return NULL;  // Handle empty list case

        // Step 1: Count the total number of nodes in the list
        int count = 0;
        ListNode* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }

        // Step 2: Check if we need to remove the head node
        if (count == n) {
            ListNode* node = head;
            head = head->next;
            delete node;
            return head;  // Return new head after deleting the old head
        }

        // Step 3: Traverse to the node just before the one to delete
        int rem = count - n;  // L - N + 1
        temp = head;
        while (rem > 1) {  // Stop at the node just before the one to delete
            rem--;
            temp = temp->next;
        }

        // Step 4: Delete the nth node from the end
        ListNode* node = temp->next;
        temp->next = temp->next->next;
        delete node;

        return head;  // Return the modified list
    }
};
