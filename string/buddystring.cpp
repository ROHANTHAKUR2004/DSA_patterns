class Solution {
public:
 
     bool checkfreq(string s){

        unordered_map<char, int> mp;

        for(auto it : s){
            mp[it]++;
        }

        for(auto it : mp){
            if(it.second > 1) return true;
        }
        return false;

  }
    bool buddyStrings(string s, string goal) {
        
        int n = s.size();
        int m = goal.size();

        if( n != m ) return false;

        vector<int> index;

        if(s == goal){
            return checkfreq(s);
        }

        for(int i=0; i< n ; i++){  
             if(s[i] != goal[i]){
                index.push_back(i);
             }
        }

        if(index.size() != 2) return false;

        swap(s[index[0]], s[index[1]]);

        return (s == goal);
    }
};