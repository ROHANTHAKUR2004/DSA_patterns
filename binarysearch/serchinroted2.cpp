class Solution {
public:
     int n;
    bool bt(int l, int r, vector<int>& nums, int target){
         while(l<=r){
             int mid = l + (r-l)/2;

             if(nums[mid] == target) return true;
             else if(nums[mid] > target) r = mid-1;
             else l = mid +1;
         }
         return false;
    }
    int findminmumidex(vector<int>& nums){
        int l = 0;
        int r = n-1;

        while(l<r){
           while(l < r && nums[l] == nums[l+1]) l++;
            int mid = l + (r-l)/2;

            if(nums[mid] > nums[r]) l = mid +1;
            else r = mid;
        }
        return l;
    }
    bool search(vector<int>& nums, int target) {
         n = nums.size();

        int pivot = findminmumidex(nums);

        bool left = bt(0, pivot-1, nums, target);
        if(left != false) return left;

        return bt(pivot, n-1, nums, target);



    }
};