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
    vector<int> rightSideView(TreeNode* root) {   vector<int> v;
        if(root==NULL) return v;
      
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        { int n=q.size();
          TreeNode *t;
         while(n--)
         {
            t=q.front();
             q.pop();
             if(t->left!=NULL) q.push(t->left);
             if(t->right!=NULL) q.push(t->right);
         }
         v.push_back(t->val);
            
        } return v;
    }
};