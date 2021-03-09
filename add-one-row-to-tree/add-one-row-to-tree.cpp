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
    void fun(TreeNode* root,int l,int v,int d)
    {
        if(root==NULL) return;
        if(l==d-1){root->left=new TreeNode(v, root->left, NULL) ;
                  root->right= new TreeNode(v, NULL, root->right); return;}
        fun(root->left,l+1,v,d);
        fun(root->right,l+1,v,d);
        
    }
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d==1) {root= new TreeNode(v,root, NULL);}
        else fun(root,1,v,d);
    return root;
    }
};