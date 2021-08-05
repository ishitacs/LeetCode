/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   bool isame(TreeNode* s, TreeNode* t){
       if(s==NULL || t==NULL){
           return s==NULL && t==NULL;
       } 
       else if(s->val == t->val){    
           return isame(s->left,t->left) && isame(s->right,t->right);
       }
       else{
           return false;
       }
   }
   bool isSubtree(TreeNode* s, TreeNode* t) {
         if(s==NULL){
             return false;
         }   
         else if(isame(s,t)){
             return true;
         }
         else{
             return isSubtree(s->left,t) || isSubtree(s->right,t);
         }
   }
};