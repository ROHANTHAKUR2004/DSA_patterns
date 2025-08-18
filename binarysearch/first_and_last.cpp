class Solution {
public:
  int n ;
  int f1(vector<int>& nums, int target){
      int lo = 0;
      int hi = n-1;

      int right_mst = -1;
      while(lo <= hi){
        int mid = lo +(hi-lo)/2;

        if(nums[mid] == target){
            right_mst = mid;
            lo = mid +1;
        }
        else if(nums[mid] > target) hi = mid-1;
        else lo = mid + 1;
      }
      return right_mst;
   }
   int f(vector<int>& nums, int target){
      int lo = 0;
      int hi = n-1;

      int left_mst = -1;
      while(lo <= hi){
        int mid = lo +(hi-lo)/2;

        if(nums[mid] == target){
            left_mst = mid;
            hi = mid-1;
        }
        else if(nums[mid] > target) hi = mid-1;
        else lo = mid + 1;
      }
      return left_mst;
   }
    vector<int> searchRange(vector<int>& nums, int target) {
         n = nums.size();

        int left = f(nums, target);
        int right = f1(nums,target);


        return {left, right};
    }
};