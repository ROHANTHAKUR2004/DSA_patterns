class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;

        if(n == 1) return nums[0];

        int sum = 0;
        int maxNum = nums[0];

        for(int i = 0; i < n; i++) {
            if (!st.count(nums[i]) && nums[i] >= 1) {
                sum += nums[i];
                st.insert(nums[i]);
            }
            if (nums[i] > maxNum) {
                maxNum = nums[i];
            }
        }

        return sum > 0 ? sum : maxNum;
    }
};
