class Solution {
public:
    vector<vector<int>> ans;
    int n;
    
    void f(int idx,vector<int>& nums, vector<int> temp){
         
        if(idx >= n){
            ans.push_back(temp);
            return;
        }
        
        //liya 
        temp.push_back(nums[idx]);
        f(idx+1, nums, temp);

        //nhi liya
        temp.pop_back();
        f(idx+1, nums ,  temp);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
       n = nums.size(); 
         vector<int> temp;
       f(0, nums, temp);
      
       return ans;
    }
};