class Solution {
public:
    int n, m;
    vector<vector<int>> dir {{1, 0}, {-1, 0}, {0, -1}, {0, 1}, {1,1}, {-1,-1}, {-1, 1}, {1, -1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
          n = grid.size();
          m = grid[0].size();

          queue<pair<int,int>> q;

          if(grid[0][0] == 1 || grid[n-1][m-1])  return -1;

          q.push({0, 0});
          grid[0][0] = 1;

          int level = 1;

          while(!q.empty()){

              int sz = q.size();

              while(sz--){

                auto it = q.front();
                q.pop();

                int row = it.first;
                int col = it.second;

                if(row == n-1 && col == m-1) return level;

                for(auto it : dir){

                    int newx = row + it[0];
                    int newc = col + it[1];

                    if(newx >= 0 && newx < n && newc >= 0 && newc < m && grid[newx][newc] == 0){
                        grid[newx][newc] = 1;
                        q.push({newx, newc});
                    }
                }

              }
              level++;
          }
          return -1;
    }
};