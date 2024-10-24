/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // Step 1: Copy the value of the next node to the current node
        node->val = node->next->val;

        // Step 2: Store the node to be deleted (which is the next node)
        ListNode* nodeToDelete = node->next;

        // Step 3: Bypass the next node
        node->next = node->next->next;

        // Step 4: Delete the bypassed node
        delete nodeToDelete;
    }
};
