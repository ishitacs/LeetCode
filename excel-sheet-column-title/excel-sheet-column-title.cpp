class Solution {
public:
    string convertToTitle(int c) {
        string r="";
        while(c)
        {
            char ch='A'+(c-1)%26 ;
            r+=ch;
            c=(c-1)/26;
        } reverse(r.begin(),r.end());
        return r;
        
    }
};