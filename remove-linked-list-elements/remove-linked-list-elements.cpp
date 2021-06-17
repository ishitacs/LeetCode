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
    ListNode* removeElements(ListNode* head, int val) {
 
        while(head&&head->val==val)
            head=head->next;
        if(head==0||head->next==0)
            return head;
        ListNode* tmp=head,*nex;

            while(tmp)
            {
                nex=tmp->next;
               while(nex&&nex->val==val)
                   nex=nex->next;
                tmp->next=nex;
                tmp=tmp->next;
            }
            return head;
        } 
        
        
    
};


  
      
            