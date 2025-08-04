class Solution {
public:
    int n;
    int dp[1000001][3][2];
    int f(int idx,vector<int>& prices, int k, bool buy ){

        if(idx >= n) return 0;

         if(k == 0) return 0;

         if(dp[idx][k][buy] != -1) return dp[idx][k][buy];

         int profit = 0;
         
         if(buy){

            int buyed = -prices[idx] + f(idx+1, prices, k , false);

            int notbuyed = f(idx +1, prices, k , true);

             profit = max(buyed,  notbuyed);

         }
         else {

            int sell = prices[idx] + f(idx +1, prices, k -1, true );

            int ntsell = 0 + f(idx +1, prices, k, false);

           profit = max(sell, ntsell);

         }
         return dp[idx][k][buy] =  profit;

    }
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        n = prices.size();
        int k = 2;
        bool buy = true;
        return f(0, prices,  k, buy); 
    }
};