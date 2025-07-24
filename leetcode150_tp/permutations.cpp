class Solution {
public:
   vector<vector<int>> ans;
   unordered_set<int> st;
   int n;
   void f(int idx, vector<int>& nums, vector<int>& temp){
           
           if(temp.size() == n){
              ans.push_back(temp);
              return;
           }

           for(int i = 0 ; i< n ; i++){
                if(st.find(nums[i]) == st.end()){
                    temp.push_back(nums[i]);
                    st.insert(nums[i]);

                    f(i, nums, temp);

                    st.erase(nums[i]);
                    temp.pop_back();
                }
           }
   }
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();

        vector<int>temp;

        f(0, nums, temp);

        return ans;
        
    }
};