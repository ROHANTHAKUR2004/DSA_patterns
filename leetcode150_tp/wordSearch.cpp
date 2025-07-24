class Solution {
public:
    int n, m;
    vector<vector<int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool find(int i, int j, vector<vector<char>>& board, int idx, string &word, vector<vector<bool>>& visited) {
        if (idx == word.size()) return true;
        if (i < 0 || i >= n || j < 0 || j >= m || visited[i][j] || board[i][j] != word[idx]) return false;

        // Mark visited
        visited[i][j] = true;
        for (auto &it : dir) {
            int new_i = i + it[0];
            int new_j = j + it[1];

            if (find(new_i, new_j, board, idx + 1, word, visited)) 
                return true;
        }

        visited[i][j] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0] && find(i, j, board, 0, word, visited)) 
                    return true;
            }
        }
        return false;
    }
};