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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*fhead=NULL;
        ListNode*ftail=NULL;
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        while(list1&&list2){
            if(list1->val<list2->val){
                if(fhead==NULL){
                    fhead=list1;
                    ftail=list1;
                }else{
                    ftail->next=list1;
                    ftail=list1;
                }
                list1=list1->next;
            }else{
                if(fhead==NULL){
                    fhead=list2;
                    ftail=list2;
                }else{
                    ftail->next=list2;
                    ftail=list2;
                }
                list2=list2->next;
            }
        }
        if(list1==NULL) ftail->next=list2;
        if(list2==NULL) ftail->next=list1;
        return{fhead};
    }
};