class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
       int n = nums.size();
       vector<int> next(n , 1), prev(n, 1);

       int prod = 1;

       for(int i=0 ; i< n; i++){
           prod = prod * nums[i];
           next[i] = prod;
       }

       prod = 1;

       for(int i= n-1;  i>=0 ; i--){
           prod = prod * nums[i];
           prev[i] = prod;
       }

       vector<int> ans(n);

       ans[0] = prev[1];
       ans[n-1] = next[n-2];

       for(int i= 1; i< n-1; i++){
          ans[i] = next[i-1] * prev[i+1];
       }

       return ans;

    }
};