class Solution {
public:
    int n, m ;
    vector<vector<int>> dir {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    void dfs(int x, int y,vector<vector<char>>& grid){
             
        grid[x][y] = '0';

        for(vector<int> &it : dir){
             
             int newx = x + it[0];
             int newy = y + it[1];

             if(newx >=0 && newx < n && newy >= 0 && newy < m && grid[newx][newy] == '1'){
                 dfs(newx, newy, grid);
             }
        }

    }

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int count = 0;

        for(int i=0; i< n; i++){
            for(int j=0; j< m; j++){

                if(grid[i][j] == '1'){
                    count++;
                    dfs(i, j, grid);
                }
            }
        }

        return count;
    }
};