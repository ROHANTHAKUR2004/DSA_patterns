class Solution {
public:
    bool dfs(int src, int currcolor, unordered_map<int, vector<int>>& mp, vector<int>& color) {
        color[src] = currcolor;

        for (auto it : mp[src]) {
            if (color[it] == currcolor)
                return false;

            if (color[it] == -1) {
                if (!dfs(it, !currcolor, mp, color))
                    return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            for (int it : graph[i]) {
                mp[i].push_back(it);
            }
        }

        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                
                // src , colorkonsakarma, mp, color
                if (!dfs(i, 0, mp, color))
                    return false;
            }
        }

        return true;
    }
};
