class Solution {
public:
    int n, m;
    vector<vector<int>> dir {{1, 0}, { 0 , 1}, { -1, 0}, {0 , -1}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& ent) {
        n = maze.size();
        m = maze[0].size();

        queue<pair<int,int>> q;

        int r = ent[0];
        int c = ent[1];

        q.push({r,c});

        int steps = 0;

        while(!q.empty()){

            int qsize = q.size();

            while(qsize--){

                auto it = q.front();
                q.pop();

                int row = it.first;
                int col = it.second;
                   
                     
                if ((row == 0 || row == n - 1 || col == 0 || col == m - 1) &&
                    !(row == ent[0] && col == ent[1])) {
                    return steps;
                }

                 for(auto &it : dir){
                      
                      int newr = row + it[0];
                      int newc = col + it[1];

                      if(newr >= 0 && newr < n && newc >=0 && newc < m && maze[newr][newc] == '.'){
                          q.push({newr, newc});
                          maze[newr][newc] = '+';
                      }
                 }
            }
            steps++;
        }
        return -1;

    }
};