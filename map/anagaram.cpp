class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp;

        for(auto it : s){
            mp[it]++;
        }

        for(int i=0; i< t.size(); i++){
            
            if(!mp.count(t[i])) return false;

            mp[t[i]]--;
            if(mp[t[i]]==0) mp.erase(t[i]);

        }
        if(mp.size() > 0) return false;
        return true;
    }

};