class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        int temp = 0;
        for(int i=0; i< nums.size(); i++){

            temp = temp ^ nums[i];
        }

        int diff = temp ^ k ;

        return __builtin_popcount(diff);
    }
};