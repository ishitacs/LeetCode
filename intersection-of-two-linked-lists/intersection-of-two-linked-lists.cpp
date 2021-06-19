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
    ListNode *helper(ListNode *h1, ListNode *h2, int diff)
    {       while(diff > 0)         
            {
                diff--;
                h1 = h1->next;
            }
            
            while(h1 != h2) 
            {
                h1 = h1->next;
                h2 = h2->next;
            }
        
            if(h1 == h2)            
                return h1;
        
            h1 = NULL;              
            return h1;
        
        }
        
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1=0,l2=0;
        ListNode *t1= headA;
        ListNode *t2= headB;
        while(t1) {l1++; t1=t1->next;}
        while(t2) {l2++; t2=t2->next;}
        int d=abs(l1-l2);
        if(l1>l2) return helper(headA,headB, d);
        else return helper(headB,headA, d);
        
    }
};