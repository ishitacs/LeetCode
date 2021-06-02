class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) { int c=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0; int j=0;
        while(i<s.size() && j<g.size())
        {
            if(s[i]>=g[j]) {i++;j++;c++;}
            else i++;
                
        } return c;
        
    }
};