class Solution {
public:
    int balancedStringSplit(string s) {
        int n = s.length();
        int ans = 0; 
        int c = 0;
        for(int i = 0 ; i<n ; i++){
            if(s[i] == 'R'){
                c++;
            }
            else{
            c--;
            }
            if(c == 0) ans++;
        }
        return ans;
    }
};