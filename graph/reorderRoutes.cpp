class Solution {
public:
    void dfs(int src, unordered_map<int, vector<pair<int,int>>> &adj,
             vector<int> &visit, int &count) {
        visit[src] = 1;

        for (auto it : adj[src]) {
            int dst = it.first;
            int nodepath = it.second;

            if (visit[dst] == -1) {
                 if (nodepath == 1) count++;
                dfs(dst, adj, visit, count);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& conn) {
        unordered_map<int, vector<pair<int,int>>> adj;

        for (int i = 0; i < conn.size(); i++) {  
            int src = conn[i][0];
            int dst = conn[i][1];

            adj[src].push_back({dst, 1});
            adj[dst].push_back({src, 0});
        }

        int count = 0;
        vector<int> visit(n, -1);

        dfs(0, adj, visit, count);

        return count;
    }
};
