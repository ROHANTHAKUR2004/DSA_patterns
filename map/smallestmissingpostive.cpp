class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // code here
        unordered_map<int, int> mp;
        
        for(auto it : arr){
            mp[it]++;
        }
        
        int count = 1;
        
        for(auto it : mp){
            
            if(mp.find(count) == mp.end()) return count;
            
            count++;
        }
        
        return count;
    }
};