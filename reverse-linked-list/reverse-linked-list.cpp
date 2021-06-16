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
        ListNode *c=head;
        ListNode *p=NULL;
        ListNode *n;
        while(c!=NULL)
        { n=c->next;
          c->next=p;
        p=c;
         c=n;
        
        } head=p;
        
    return head;}
};