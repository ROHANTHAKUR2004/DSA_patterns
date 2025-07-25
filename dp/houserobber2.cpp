class Solution {
public:
   int dp[101];
    int f(int idx ,int n, vector<int>& nums ){
         if(idx >= n) return 0;

         if(dp[idx] != -1) return dp[idx];

         int tke = nums[idx] + f(idx +2 ,n,  nums);
         int nt = 0 + f(idx+1,n,nums);

         return dp[idx] =  max(tke, nt);
    }
    int rob(vector<int>& nums) {
         int  n = nums.size();
         if(n ==1) return nums[0];
        
         memset(dp, -1, sizeof(dp));
         int first = f(0,n-1, nums);

         memset(dp, -1, sizeof(dp));
         int last = f(1,n, nums);

         return max(first, last);
    }
};