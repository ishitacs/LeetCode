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
           vector<ListNode*> a;
        ListNode* temp=head;
        int i=0;
        while(temp!=NULL)
        { a.push_back(temp);
            temp=temp->next;
         }
 int t1=a[k-1]->val;
        a[k-1]->val=a[a.size()-k]->val;
        a[a.size()-k]->val=t1;
        return head;
        
    }
};