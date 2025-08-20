class Solution {
public:
    bool canans(int n, int index, int maxsum, int mid){
        long long sum = mid;  

        int leftcount = index;
        int rightcount = n - index - 1;


        if(mid > leftcount){
            long long high = mid - 1;
            long long low = mid - leftcount;
            sum += (high + low) * leftcount / 2;
        } else {
            long long high = mid - 1;
            sum += (high + 1) * high / 2;       
            sum += (leftcount - (mid - 1));    
        }

     
        if(mid > rightcount){
            long long high = mid - 1;
            long long low = mid - rightcount;
            sum += (high + low) * rightcount / 2;
        } else {
            long long high = mid - 1;
            sum += (high + 1) * high / 2;
            sum += (rightcount - (mid - 1));
        }

        return sum <= maxsum;
    }

    int maxValue(int n, int index, int maxsum) {
        int l = 1;
        int r = maxsum;
        int ans = 1;

        while(l <= r){
            int mid = l + (r - l) / 2;
            if(canans(n, index, maxsum, mid)){
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
