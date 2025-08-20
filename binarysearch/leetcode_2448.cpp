class Solution {
public:
   int n;
   long long canans(vector<int>& nums, vector<int>& cost , int mid){

    long long ct = 0;

    for(int i=0; i< n; i++){
        
        int steps = abs(mid - nums[i]);

        ct += (long long) steps * cost[i];
    }

    return ct;

   }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        
        long long ans = INT_MAX;
         
         n = nums.size();

         int l = *min_element(nums.begin(), nums.end());
         int r = *max_element(nums.begin(), nums.end());


         while(l<=r){

            int mid = l + (r-l)/2;

            long long price = canans(nums, cost, mid);

            // main  cracks where to move right or left
            long long price2 = canans(nums, cost, mid + 1);

            ans = min(price, price2);

            if(price2 > price){
                r = mid -1;
             }
             else l = mid +1 ;
         }
 
         return ans == INT_MAX ? 0 : ans;

    }
};