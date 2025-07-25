class Solution {
public:
    int n;
       int dp[13][1000001];
      int f( int i,vector<int>& coins, int amount ){
            if( i >= n || amount < 0) return 1e9;
            if( amount == 0) return 0;
            if(dp[i][amount] !=  -1) return dp[i][amount];
           int take =  1 + f( i , coins , amount - coins[i]);
           int nottake = f( i+1 , coins , amount);
    
            return dp[i][amount] =  min(take,nottake);
      }
    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        memset(dp , -1, sizeof(dp));
        int ans =  f(0, coins , amount);

        return  ans == 1e9 ? -1 : ans;
    }
};