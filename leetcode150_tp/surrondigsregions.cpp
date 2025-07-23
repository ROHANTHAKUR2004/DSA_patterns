class Solution {
public:
    int n , m;
    vector<vector<int>> dir {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    void dfs(int x, int y,vector<vector<char>>& board){
         
         board[x][y] = 'Z';

         for(auto it : dir){
              int newx = x + it[0];
              int newy = y + it[1];

              if(newx >= 0 && newx < n && newy >= 0 && newy < m && board[newx][newy] == 'O'){
                  dfs(newx, newy, board);
              }
         }
    }
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();

        int firstrow = 0;
        int lastrow = n-1; 
        int firstcol = 0;
        int lastcol = m-1;

        for(int i=0 ; i< m ; i++){
            if(board[firstrow][i] == 'O'){
                dfs(firstrow, i, board);
            }
            if(board[lastrow][i] == 'O'){
                dfs(lastrow, i, board);
            }   
        }
        for(int i=0 ; i< n ; i++){
            if(board[i][firstcol] == 'O'){
                dfs( i, firstcol,  board);
            }
            if(board[i][lastcol] == 'O'){
                dfs(i,lastcol,  board);
            }   
        }

        for(int i=0; i< n; i++){
             for(int j=0; j < m ; j++){
                 if(board[i][j] == 'Z'){
                    board[i][j] = 'O';
                 }
                 else board[i][j] = 'X';
             }
        }
    }
};