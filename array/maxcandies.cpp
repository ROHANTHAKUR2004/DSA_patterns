class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extra) {
        vector<bool> ans;

        int maxele = *max_element(candies.begin(), candies.end());

        for(int i=0; i< candies.size(); i++){
            if(candies[i] + extra >= maxele){
                ans.push_back(true);
            }
            else ans.push_back(false);
        }
        return ans;
    }
};