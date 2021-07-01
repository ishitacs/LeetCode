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
    vector<string> path(TreeNode* root, string s, vector<string> &v)
    {s+=to_string(root->val);
     if(root->left==NULL && root->right==NULL)
     { v.push_back(s);
       return v; }
     s+="->";
     if(root->left!=NULL)
     path(root->left,s,v);
     if(root->right!=NULL)
    path(root->right,s,v);
     return v;
     
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string s; vector <string>v;
        path(root,s,v);
        return v;
    }
};