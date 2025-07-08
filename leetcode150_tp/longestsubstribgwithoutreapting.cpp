class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        int n =  s.size();
        int i =0, j=0;
        int len = 0;
        unordered_map<char, int> mp; 
        while(j < n){

           while(mp.count(s[j])){
               mp[s[i]]--;
               if(mp[s[i]] == 0) mp.erase(s[i]);
               i++;
           }
            mp[s[j]]++;
            len = max(len, j - i + 1);
            j++;

        }
        return len;

    }
};