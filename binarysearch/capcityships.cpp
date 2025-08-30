class Solution {
public:
    int n;
     bool canship(vector<int>& weights, int cap, int days) {
        int tkendays = 1; 
        int sum = 0;

        for (int i = 0; i < n; i++) { 
            if (weights[i] > cap) return false;
            
            if (sum + weights[i] > cap) {
                tkendays++;
                sum = 0;
            }
            sum += weights[i];
        }

        return tkendays <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        n = weights.size();
        int totalsum =0;
        for(int i=0; i< n; i++){
            totalsum += weights[i];
        }

        int l = 1;
        int r = totalsum;

        int ans = 0;

        while(l <=r){

            int mid = l +(r-l)/2;

            if(canship(weights, mid, days)){
                ans = mid;
                r = mid -1;
            }
            else l = mid +1;
        }


        return ans;

    }
};