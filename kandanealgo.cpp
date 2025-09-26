class Solution {
public:
   int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int mxsum =nums[0];
        for(int i=1; i< nums.size(); i++){
            sum = max(sum+ nums[i], nums[i]);
            mxsum = max(sum , mxsum);
        }
        return mxsum;
    }

    int minSubArray(vector<int>& nums) {
        int sum = nums[0];
        int minsum =nums[0];
        for(int i=1; i< nums.size(); i++){
            sum = min(sum+ nums[i], nums[i]);
            minsum = min(sum , minsum);
           
        }
        return minsum;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int totalsum = 0;
        for(int i=0; i< n; i++){
            totalsum += nums[i];
        }
        
        int minsum = minSubArray(nums);

        int maxsum = maxSubArray(nums);

        int circularsum = totalsum - minsum;// important

        if(maxsum > 0){
            return max(maxsum ,circularsum );

        }

        return maxsum;


    }
};