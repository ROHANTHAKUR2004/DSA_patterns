class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;

        int sum = 0;

        int ans = 0;

        int i=0, j=0;

        while(j < n){
            while(st.count(nums[j])){
                  ans = max(ans, sum);
                  sum -= nums[i];
                  st.erase(nums[i]);
                  i++;     
            }

            
            st.insert(nums[j]);
            sum += nums[j];
            j++;
        }
        ans = max(ans , sum);
        return ans;
    }
};