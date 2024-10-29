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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0) return head;
        ListNode* temp=head;
        ListNode* tail=head;
        int size=0;
        while(temp!=NULL){
            if(temp->next==NULL)
            {
                tail=temp;
            }
            temp=temp->next;
            size++;
        }
        
        k=k%size;
        temp=head;
        if(k==0) return head;
        for(int i=1;i<size-k;i++){
            temp=temp->next;
            
        }
        ListNode* newhead=temp->next;
        temp->next=NULL;
        tail->next=head;
        return newhead;
    }
};