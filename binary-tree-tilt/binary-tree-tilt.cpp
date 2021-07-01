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
    int help(TreeNode* root,int &sum){
        if(!root) return 0;
        int l=help(root->left,sum);
        int r=help(root->right,sum);
        sum=sum+ abs(l-r);
        return l+r+root->val;
        
    }
    int findTilt(TreeNode* root) {
        int sum=0;
        help(root,sum);
        return sum;
    }
};