class Solution {
public:
    vector<vector<int>> ans;
    int n;
    void f(int idx,vector<int>& cand, int target,  vector<int> &temp ){
        if(target == 0){
            ans.push_back(temp);
            return ;
        }
        if( idx >= n) return ;

        temp.push_back(cand[idx]);
        if(target > 0) f(idx, cand, target - cand[idx], temp);
        temp.pop_back();
        f(idx+1, cand, target, temp);
    }
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
      n = cand.size();
      vector<int> temp;

      f(0, cand, target, temp);

      return ans;
    }
};