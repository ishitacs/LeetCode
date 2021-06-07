class Solution {
public:
    string removeOuterParentheses(string s) { int open=0; string ans="";
        for(int i=0;i<s.size();i++)
        {
            if(open==0 && s[i]=='(') open++;
           else if(open==1 && s[i]==')') open--;
            else {
                if(s[i]=='(') open++;
                else open--;
                ans+=s[i];
            }
        } return ans;
    }
};