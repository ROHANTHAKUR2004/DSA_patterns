class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> ans(n, 0);
        vector<int> pos;

        for(int i = 0; i < n; i++) {
            if(s[i] == c) {
                pos.push_back(i);
            }
        }
        
        for(int i = 0; i < n; i++) {
            
            int diff = INT_MAX;
            
            for(int idx : pos) {
                
                diff = min(diff, abs(i - idx));
                
            }
            ans[i] = diff;
        }

        return ans;
    }
};
