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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n) return head;
        int c=1;
        ListNode* cn=head; ListNode* pn=NULL;
        while(c!=m)
        {
            pn=cn;
            cn=cn->next;
            c++;
        }
        ListNode* M=cn;
        ListNode* Mp=pn;
         ListNode* nn;
        while(c<=n)
        {
            nn= cn->next;
            cn->next=pn;
            pn=cn;
            cn=nn;
            c++;
        }
        M->next = cn;
	if( Mp != NULL )
		Mp->next =  pn;
	else 
		head = pn;
	return head; 
    }
};