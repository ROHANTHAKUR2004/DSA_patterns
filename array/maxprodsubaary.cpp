class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];

        int prod = 1;
        for (int j = 0; j < n; j++) {
            prod *= nums[j];
            ans = max(ans, prod);
            if (prod == 0) prod = 1;  
        }
        prod = 1;
        for (int j = n - 1; j >= 0; j--) {
            prod *= nums[j];
            ans = max(ans, prod);
            if (prod == 0) prod = 1;
        }

        return ans;
    }
};
