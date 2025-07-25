class Solution {
public:
    int n;
    int dp[101];
    int f(int idx ,vector<int>& nums ){
         if(idx >= n) return 0;

         if(dp[idx] != -1) return dp[idx];

         int tke = nums[idx] + f(idx +2 , nums);
         int nt = 0 + f(idx+1, nums);

         return dp[idx] =  max(tke, nt);
    }
    int rob(vector<int>& nums) {
         n = nums.size();
         memset(dp, -1, sizeof(dp));
         if(n ==1) return nums[0];
         if(n==2) return max(nums[0], nums[1]);

        
        return f(0,nums);
    }
};