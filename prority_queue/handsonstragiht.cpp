class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false; 

        map<int, int> mp;
        for (int card : hand) {
            mp[card]++;
        }

        for (auto& [card, freq] : mp) {
            if (freq > 0) {
                int need = freq; 
                for (int i = 0; i < groupSize; i++) {
                    int cur = card + i;
                    if (mp[cur] < need) return false;
                    mp[cur] -= need;
                }
            }
        }
        return true;
    }
};
