class Solution {
public:
    int sumSubseqWidths(vector<int>& v) {
         int n = v.size();
        const long long mod = 1000000007;
        sort(v.begin(), v.end());
        vector<long long> power_2(n, 1);
        for(int i = 1;i < n;i++)
            power_2[i] = (power_2[i - 1] << 1) % mod;
        long long res = 0;
        for(int i = 0;i < n;i++)
            res = (res + v[i] * (power_2[i] - power_2[n - i - 1])) % mod;
        return res;
        
    }
};