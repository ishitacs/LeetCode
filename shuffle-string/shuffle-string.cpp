 class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ans="";
        int n=s.length();
        char arr[n];//to store characters in the specified order
        for(int i=0;i<indices.size();i++){
            arr[indices[i]]=s[i];
        }
        // to concatenate 
        for(int i=0;i<n;i++){
            ans+=arr[i];
        }
        return ans;
    }
};