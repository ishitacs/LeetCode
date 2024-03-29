 class Solution {
public:
    vector<int> p;
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        p.resize(n + 1);
        for (int i = 1; i <= n; i ++) p[i] = i;
        vector<int> indegree(n + 1);
        for (auto edge : edges) {
            indegree[edge[1]] ++;
        }
        vector<vector<int>> conflicts;
        for (auto edge : edges) {
            if (indegree[edge[1]] > 1) {
                conflicts.push_back(edge);
            }
        }
        
        if (conflicts.size() > 0) {
            if (isTreeByRemoveEdge(edges, conflicts[1])) {
                return conflicts[1];
            }
            else return conflicts[0];
        }
        return getTreeByCircle(edges);
    }
    bool isTreeByRemoveEdge(vector<vector<int>>& edges, vector<int>& x) {
        for (auto edge : edges) {
            if (edge == x) continue;
            int a = find(edge[0]), b = find(edge[1]);
            if (a == b) return false;
            p[b] = a;
        }
        return true;
    }
    vector<int> getTreeByCircle(vector<vector<int>>& edges) {
        for (auto edge : edges) {
            int a = find(edge[0]), b = find(edge[1]);
            if (a == b) return edge;
            p[b] = a;
        }
        return {};
    }
    int find(int a) {
        if (p[a] != a) p[a] = find(p[a]);
        return p[a];
    }
};