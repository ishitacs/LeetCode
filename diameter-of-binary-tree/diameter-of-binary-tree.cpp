 class Solution {
public:
    int res = 0;
    int check(TreeNode* root){
        if(!root)
            return 0;
        
        int leftHeight = check(root->left);
        int rightHeight = check(root->right);
        
        res = max(res, leftHeight + rightHeight);
        

        return 1 + max(leftHeight, rightHeight);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        check(root);
        return res;
    }
};