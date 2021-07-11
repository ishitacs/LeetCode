class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) { 
     string a=strs[0];
        for(int i=1;i<strs.size();i++)
        {
            string b= strs[i];
            string s="";
            int j=0; int k=0;
            while(j<a.length() && k<b.length())
            { if(a[j]==b[k]) s+=a[j];
                else break;
             k++;
             j++;
            }
            a=s;
        }return a;
    }
};