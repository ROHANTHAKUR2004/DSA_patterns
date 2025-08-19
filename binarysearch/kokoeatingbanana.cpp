class Solution {
public:
    int n ;
    bool caneat(vector<int>& piles, int h , int mid){
        long long time = 0;
        for(int i=0; i< n; i++){
            if(piles[i] <= mid) time += 1;
            else {
               int divi = piles[i]/mid;
               int rem = piles[i]% mid;
               time += divi + (rem > 0 ? 1 : 0);
            }
        }
        return time <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        n = piles.size();

        int ans = 0;

        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        while(l <= r){

             int mid = l + (r-l)/2;

             if(caneat(piles, h, mid) == true){
                 ans = mid;
                 r = mid -1;
             } 
             else l = mid +1;
        }
        return ans;
    }
};