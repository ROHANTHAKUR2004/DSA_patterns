class Solution {
public:
    int n;
    int dp[300005][2];
    int f(int idx , vector<int>& prices, int fee, bool buy){

        if(idx >= n) return 0;

         if(dp[idx][buy]!= -1) return dp[idx][buy];

        int profit =0;

        if(buy){
             // buy karo`

            int by = -prices[idx] + f(idx +1, prices, fee, false);

            int nbuy =  f(idx +1, prices, fee, true);

            profit = max(by, nbuy);

        }
        else {
            // sell karo

            int sell = prices[idx] + f(idx +1, prices, fee, true) - fee;

            int notsell = 0 + f(idx +1, prices, fee, false);

            profit = max(sell, notsell);
        }

        return dp[idx][buy] =  profit;
        
    }
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp, -1  , sizeof dp);
        n = prices.size();

        bool buy = true;

        return f(0,prices, fee, buy);
    
    }
};