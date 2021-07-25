 class Solution {
public:
    int hIndex(vector<int>& c) {
        int save[1001];
        int n=c.size();
        memset(save,0,sizeof(save));
        for(int i=0;i<n;i++)
        {
            save[c[i]]++;
        }
        int sum=0;
        for(int i=1000;i>=0;i--)
        {
            int t=save[i];
            if(sum+t>=i)
                return i;
            sum+=t;
        }
        return -1;
    }
};