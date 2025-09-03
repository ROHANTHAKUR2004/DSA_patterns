class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        int idx = 0;
        int zeros = 0;

        for(int i=0; i< n ; i++){
            if(nums[i]==0) zeros++;
            else {
                nums[idx] = nums[i];
                idx++;
            }
        }
        while(zeros--){
            nums[idx] = 0;
            idx++; 
        }  
    }
};