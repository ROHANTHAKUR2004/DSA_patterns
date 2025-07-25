class Solution {
public:
    bool canConstruct(string rans, string mag) {
        unordered_map<char,int> mp;

        for(auto it : mag){
            mp[it]++;
        }
        for(int i=0; i< rans.size(); i++){

            if(mp.find(rans[i]) == mp.end()) return false;

            mp[rans[i]]--;
            if(mp[rans[i]] == 0) mp.erase(rans[i]);
        }
        return true;
    }
};