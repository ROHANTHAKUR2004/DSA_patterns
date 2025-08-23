class Solution {
public:
    void dfs(int src, vector<bool> &visited, unordered_map<int, vector<int>> &adj) {
        visited[src] = true;
        for (auto neighbor : adj[src]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited, adj);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isconn) {
        int n = isconn.size();
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isconn[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                }
            }
        }

        vector<bool> visited(n, false);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                dfs(i, visited, adj);
            }
        }

        return count;
    }
};