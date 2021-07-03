class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = size(matrix), n = size(matrix[0]); 
        vector<vector<int>> rsum(m, vector<int>(n+1)); 
        
        int ans = INT_MIN; 
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i) rsum[i][j+1] = matrix[i][j] + rsum[i][j]; 
            for (int jj = 0; jj <= j; ++jj) {
                int prefix = 0; 
                set<int> seen; 
                for (int i = 0; i < m; ++i) {
                    seen.insert(prefix); 
                    prefix += rsum[i][j+1] - rsum[i][jj]; 
                    auto it = seen.lower_bound(prefix - k); 
                    if (it != seen.end()) ans = max(ans, prefix - *it); 
                }
            }
        }
        return ans; 
    }
};