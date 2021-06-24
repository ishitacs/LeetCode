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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==NULL && head->next==NULL){
            return head;
        }
        ListNode* f=head;
        ListNode* s=head;
        int i=k-1;
        while(i--){f=f->next; }
        ListNode* t=f;
        while(f->next!=NULL)
        {
            s=s->next;
            f=f->next;
        }
       // ListNode* h= t->next;
       //  t->next=s->next;
       //  s->next=h;
        swap(t->val,s->val);
        return head;
    }
};