  unordered_map<char,int>m;
 bool comperator(char &a,char &b){
        if(m[a]<m[b]){
            return true;
        }
        return false;
    }
class Solution {
public:
    string customSortString(string order, string str) {
        for(int i=0;i<order.length();i++){
            m[order[i]]=i;
        }
        map<char,int>m;
        sort(str.begin(),str.end(),comperator);
        return str;
    }
};