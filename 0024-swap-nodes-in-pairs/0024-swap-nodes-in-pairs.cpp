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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* dummynode=new ListNode(); //keep the returning head node
        ListNode* prenode; //track the previous node
        ListNode* current; //track the current node
        dummynode->next=head;
        prenode=dummynode;
        current=head;
        while(current&&current->next){
            prenode->next=current->next;
            current->next=prenode->next->next;
            prenode->next->next=current;
            prenode=current;
            current=current->next;
        }
        return dummynode->next;  
        delete dummynode; //delete the memory allocated
    }
    //this is the iterative method its time is O(n) and space is O(1)
};