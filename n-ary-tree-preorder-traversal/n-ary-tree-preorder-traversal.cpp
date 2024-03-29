/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int>res;
    void pr(Node* root)
    {
        if(root!=NULL)
        {
            res.push_back(root->val);
            for(auto c:root->children)
                pr(c);
        }
    }
    vector<int> preorder(Node* root) {
        pr(root);
        return res;
    }
};