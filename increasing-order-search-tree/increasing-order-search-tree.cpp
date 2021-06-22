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
    vector<int>v;
    void in(TreeNode* root){
        if(root!=NULL)
        {
            in(root->left);
            v.push_back(root->val);
            in(root->right);
        }
    }
    TreeNode* increasingBST(TreeNode* root) {
      
        in(root);
        TreeNode * n=new TreeNode(v[0]);
         TreeNode * temp=n;
        for(int i=1;i<v.size();i++)
        {
             TreeNode * no=new TreeNode(v[i]);
            temp->right=no;
            temp=no;
        }
        return n;
    }
};