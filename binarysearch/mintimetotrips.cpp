class Solution {
public:
   bool cando(vector<int>& time, int totaltrips, long long mid){
       long long sum = 0;
       for(int i=0; i< time.size(); i++){
          sum += (mid/time[i]);
          if(sum >= totaltrips) return true;
       }
       return false;
   }
    long long minimumTime(vector<int>& time, int totaltrips) {
        int n = time.size();

        long long ans = 0;

        long long l = 1 ;
        long long r = (long long) totaltrips * *min_element(time.begin(), time.end());

        while(l <= r){

           long long mid = l + (r-l)/2;

            if(cando(time, totaltrips, mid)== true){
                ans = mid;
                r = mid -1;
            }else {
                l = mid +1;
            }
        }
        return ans;
    }
};