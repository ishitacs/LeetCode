class Solution {
public:
    vector<int> grayCode(int n) {
         
        int no=1<<n;
        vector<int> ans(no,0);
        for(int i=0;i<no;i++){
            ans[i]=i^ (i>>1);
        }
        return ans;
    }
};