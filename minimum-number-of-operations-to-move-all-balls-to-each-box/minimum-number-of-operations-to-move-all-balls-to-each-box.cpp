class Solution {
public:
    vector<int> minOperations(string b) {
        vector<int> ans; int c=0;
        for(int i=0;i<b.size();i++)
        { c=0;
            for(int j=0;j<b.size();j++)
            { if(b[j]=='1') c+=abs(i-j);
            } ans.push_back(c); 
        
        }
    return ans;}
};