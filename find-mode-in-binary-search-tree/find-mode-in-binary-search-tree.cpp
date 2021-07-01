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
    
    void in(TreeNode* root ,vector<int>&v)
        
    {   
        if(root==NULL) return;
        in(root->left,v);
        v.push_back(root->val);
     in(root->right,v);
     
    }
    vector<int> findMode(TreeNode* root) {
       vector<int>v;
        vector<int>r;
        in(root,v);
        unordered_map<int,int>mp;
        for(auto i:v)
        {
            mp[i]++;
        }
        int c=0;
        for(auto[x,f]:mp)
        {
            c=max(c,f);
        }
        for(auto[x,f]:mp)
        {
            if(c==f) r.push_back(x);
        }
        return r;
        
    }
};