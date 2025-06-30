class Solution {
public:
    int n;
    bool f(int idx, int k, int target, vector<int>& nums, vector<vector<vector<int>>>& dp) {
        if (k == 0) return target == 0;
        if (idx >= n) return false;
        if (dp[idx][k][target] != -1) return dp[idx][k][target];

        // Take nums[idx]
        bool take = false;
        if (target >= nums[idx])
            take = f(idx + 1, k - 1, target - nums[idx], nums, dp);

        // Or don't take
        bool nottake = f(idx + 1, k, target, nums, dp);

        return dp[idx][k][target] = take || nottake;
    }

    bool splitArraySameAverage(vector<int>& nums) {
        n = nums.size();
        int sum = 0;
        for (int x : nums) sum += x;

        sort(nums.begin(), nums.end());

        for (int k = 1; k < n; k++) {
            if ((sum * k) % n != 0) continue;

            int target = (sum * k) / n;

            vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(target + 1, -1)));

            if (f(0, k, target, nums, dp))
                return true;
        }

        return false;
    }
};
