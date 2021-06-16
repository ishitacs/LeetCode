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
    int len(ListNode* head){ stack<int>s;
                            int l=0;
        ListNode* n=head;
        while(n!=NULL)
        { l++;
         n=n->next;
        } return l;
    }
    bool isPalindrome(ListNode* head) { stack<int>s;
        if(head==NULL) return true;
        ListNode* fir=head;
        ListNode* sec=head->next;
        while(sec!=NULL )
        { s.push(fir->val);
         fir=fir->next;
         if(sec->next!=NULL)sec=sec->next->next;
        else break;}
                                      
        int l=len(head);
       if(l%2!=0) fir=fir->next;
    while(fir!=NULL && !s.empty())
    { if(fir->val!=s.top()) return false;
            s.pop();
            fir=fir->next;
    }return true;
    }
};