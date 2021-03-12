class Solution {
public:
    int arrangeCoins(int n) {
     int c=0;
        int i=1;
        while(n>=0)
        {
            n=n-i;
            c++;
            i++;
        }
        return  c-1;
    }
};