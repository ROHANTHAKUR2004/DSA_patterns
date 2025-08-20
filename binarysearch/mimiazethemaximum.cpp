class Solution {
public:
   int n;
   bool canans(vector<int>nums, int mid){

    vector<long long> arr(nums.begin(), nums.end());

      for(int i=0; i<n-1; i++){  

        if( arr[i] > mid) return false;
        long long steps = mid - arr[i];
        arr[i+1] = arr[i+1] - steps;   


      }
      if(arr[n-1] > mid) return false;  
      return true;                    
   }

   int minimizeArrayValue(vector<int>& nums) {
        n = nums.size();

        int l = nums[0];
        int r = *max_element(nums.begin(), nums.end());
        int ans = 0;

        while(l <= r){
            int mid = l + (r-l)/2;
            if(canans(nums, mid)){
                ans = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        return ans;
   }
};
