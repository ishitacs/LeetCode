 class DSU {
    vector<int> parent;    
    public:
    DSU(int n) {
        parent.resize(n, -1);
    }
    int getParent(int a) {
        return (parent[a] == -1 ? a : getParent(parent[a]));
    }
    void merge(int a, int b) {
        a = getParent(a);
        b = getParent(b);
        if(a > b)
            swap(a, b);
        if(a != b)
            parent[b] = a;
    }
};

const int SEP = 500;

class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int i, j, m = matrix.size(), n = matrix[0].size();
        map<int, vector<int>> mp;
        vector<vector<int>> ret(m, vector<int>(n, 0));
        for(i=0; i<m; i++)
            for(j=0; j<n; j++) {
                int index = i * SEP + j;
                mp[matrix[i][j]].push_back(index);
            }
        vector<int> max_x(m, 0), max_y(n, 0);
        for(auto rec : mp) {
            auto &indexes = rec.second;
            DSU dsu(m + SEP + n);
            for(auto index : indexes) {
                int x = index / SEP;
                int y = index % SEP;
                dsu.merge(x, y + SEP);
            }
            unordered_map<int, vector<int>> partitions;
            for(auto index : indexes) {
                int p = dsu.getParent(index / SEP);
                partitions[p].push_back(index);
            }
            for(auto partition : partitions) {
                auto &a = partition.second;
                int x_rank = 0, y_rank = 0;
                for(i=0; i<a.size(); i++) {
                    int x = a[i] / SEP;
                    int y = a[i] % SEP;
                    x_rank = max(x_rank, max_x[x]);
                    y_rank = max(y_rank, max_y[y]);
                }
                int rank = max(x_rank, y_rank) + 1;
                for(i=0; i<a.size(); i++) {
                    int x = a[i] / SEP;
                    int y = a[i] % SEP;
                    ret[x][y] = rank;
                    max_x[x] = rank;
                    max_y[y] = rank;
                }
            }
        }
        return ret;
    }
};