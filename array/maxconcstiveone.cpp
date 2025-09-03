class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();

        int i= 0;
        int j = 0;

        int  maxlen =INT_MIN;

        while(j < n){
             
             if(nums[j] ==0){
                while(i <=j){
                    maxlen = max(maxlen, j-i);
                    i++;
                }
             }
            j++; 

        }
        maxlen = max(maxlen , j-i);
        return maxlen;
    }
};