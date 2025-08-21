class Solution {
public:
    int m;
    bool canans(vector<int>& batteries, long long want, long long mid, int n) {
        long long sum = 0;
        for (int i = 0; i < m; i++) {
            sum += min((long long)batteries[i], mid);
        }
        return sum >= want;
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        long long ans = 0;
        m = batteries.size();

        long long totalsum = 0;
        for (int i = 0; i < m; i++) {
            totalsum += batteries[i];
        }

        long long l = 0, r = totalsum / n; 

        while (l <= r) {
            long long mid = l + (r - l) / 2;
            long long want = (long long)n * mid;

            if (canans(batteries, want, mid, n)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
