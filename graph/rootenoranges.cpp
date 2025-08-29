class Solution {
public:
   int n, m;
   vector<vector<int>> dir {{1, 0}, {0,1}, {-1, 0}, {0, -1}};
    int orangesRotting(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int freshcount = 0;

        queue<pair<int,int>> q;

        for(int i=0; i< n; i++){
            for(int j=0; j< m ; j++){
                 
                 if(grid[i][j] == 1) freshcount++;
                 else if(grid[i][j] == 2){
                    q.push({i, j});
                 }
            }
        }
        if(freshcount == 0) return 0;

        int level = 0;

        while(!q.empty()){

            int sz = q.size();

           while(sz--){
            auto it = q.front();
            q.pop();

            int row = it.first;
            int col = it.second;

            for(auto it : dir){
                 
                 int newr = row + it[0];
                 int newc = col + it[1];

                 if(newr >=0 && newr < n && newc >=0 && newc < m && grid[newr][newc] == 1){
                      freshcount--;
                      grid[newr][newc] = 2;
                      q.push({newr, newc});
                 }
             }
          }
          level++;
        }

        if(freshcount >= 1) return -1; 
        return level-1;
        
    }
};