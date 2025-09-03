class Solution {
public:
   void f(int i, int j, vector<int>& nums ){
       while(i<j){
           swap(nums[i] , nums[j]);
           i++;
           j--;
       }
   }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        k = k%n;
        f(0, n-k-1, nums);
        f(n-k, n-1, nums);
        f(0, n-1, nums);
    }
};