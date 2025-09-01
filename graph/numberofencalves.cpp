class Solution {
public:
    int n , m;
    vector<vector<int>> dir {{1, 0}, {0, 1}, { -1, 0}, {0 , -1}};
    void dfs(int row, int col , vector<vector<int>>& grid ){

        grid[row][col] = 0;

        for(auto it : dir){
            int newr = row + it[0];
            int newc = col + it[1];

            if(newr >=0 && newc >=0 && newr < n && newc < m && grid[newr][newc] == 1){
                dfs(newr, newc, grid);
            }
        }

    }
    int numEnclaves(vector<vector<int>>& grid) {
         n = grid.size();
         m = grid[0].size();

        int  row = 0, lastrow= n-1, col = 0 , lastcol = m-1;

        for(int j=0; j< m; j++){
            if(grid[row][j] == 1){
                dfs(row, j, grid);
            }
        }
        for(int j=0; j< m; j++){
            if(grid[lastrow][j] == 1){
                dfs(lastrow, j, grid);
            }
        }
        for(int i=0; i< n; i++){
            if(grid[i][col] == 1){
                dfs(i, col,  grid);
            }
        }
        for(int i=0; i< n; i++){
            if(grid[i][lastcol] == 1){
                dfs(i, lastcol,  grid);
            }
        }


        // last main count ones;
        int count =0;

        for(int i=0; i< n; i++){
            for(int j=0; j < m ; j++){
                if(grid[i][j] == 1){
                    count++;
                }
            }
        }

        return count;
  
    }
};