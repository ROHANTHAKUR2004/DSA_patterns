class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;

        int n = s.size();

        if(n ==0) return 0;

        int i =0, j=0;

        int maxlen = INT_MIN;

        while(j < n){
            
            while(st.count(s[j])){
               st.erase(s[i]);
               i++;
            }

            st.insert(s[j]);
            maxlen = max(maxlen , j-i+1);
            j++;

        }
        return maxlen;
    }
};