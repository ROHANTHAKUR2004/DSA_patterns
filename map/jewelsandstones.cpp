class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, int> mp;
        
        for (char ch : stones) {
            mp[ch]++;
        }

        int count = 0;

        for (char ch : jewels) {
            if (mp.find(ch) != mp.end()) {
                count += mp[ch];
            }
        }

        return count;
    }
};
