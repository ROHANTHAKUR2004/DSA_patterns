class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int pairs = 0;

        for (int num : nums) {
            int remaining = k - num;
            if (mp[remaining] > 0) {
                pairs++;
                mp[remaining]--;
            } else {
                mp[num]++; 
            }
        }

        return pairs;
    }
};
