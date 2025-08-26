class Solution {
public:
  int n, m;
  int dp[101][101];
  int f(int i, int j){
       
       if( i >= n || j >= m ) return 0;
       if( i == n-1 && j == m-1) return 1;

       if(dp[i][j] != -1) return dp[i][j];
       return dp[i][j] =  f(i+ 1, j) + f(i , j +1);
  }
    int uniquePaths(int M, int N) {
       n = M;
       m = N;
      memset(dp, -1, sizeof(dp));
       return f(0, 0);    
    }
};