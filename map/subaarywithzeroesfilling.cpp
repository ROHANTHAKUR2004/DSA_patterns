class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
       long long ans = 0;
       int n = nums.size();

       unordered_map<int,long long> mp;
       long long count = 0;

       for(int i=0; i< n; i++){
         if(nums[i] == 0){
            count++;
            mp[count]++;
         }
         else count = 0;  
       } 

       for(auto it : mp){
          ans += it.first * it.second;
       }

       return ans;
    }
};