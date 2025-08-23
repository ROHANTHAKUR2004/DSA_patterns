class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = -1e9;   
        int n = nums.size();

        int i = 0;
        int j = 0;
        double sum = 0;

        while (j < n) {
            sum += nums[j];
            if (j - i + 1 == k) {  
                ans = max(ans, sum / k);
                sum -= nums[i];  
                i++;
            }
            j++;
        }

        return ans;
    }
};

