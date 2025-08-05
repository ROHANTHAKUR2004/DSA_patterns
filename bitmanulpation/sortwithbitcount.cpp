class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {

        priority_queue<pair<int,int>> pq;

        for(int i=0; i< arr.size(); i++){
            int bit = __builtin_popcount(arr[i]);
            pq.push({bit, arr[i]});
        }

        vector<int> ans;
        while(!pq.empty()){ 
            auto it = pq.top();
            pq.pop();

            ans.push_back(it.second);
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};