class Solution {
public:
    int m ;
    int bt(vector<int>& potions, long long target){ // lowe bound

        int l = 0;
        int r = m-1;

        int lo = -1;

        while( l <=r){
            
            int mid = l + (r-l)/2;

            if(potions[mid] >= target){
                lo = mid;
                r = mid-1;
            }
            else l = mid +1;
        }
        return lo;
    }
   
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        m = potions.size();
        sort(potions.begin(), potions.end());

        int maxtarget = potions[m-1];

        vector<int>ans(n);

        for(int i= 0; i< n; i++){
            
            long long target = ceil((1.0 *success)/spells[i]);

            if(target > maxtarget){
                ans[i] = 0;
                continue;
            }

            int idx = bt(potions, target);

            int count = m- idx;
            ans[i] = count;
        }
        return ans;
    }
};