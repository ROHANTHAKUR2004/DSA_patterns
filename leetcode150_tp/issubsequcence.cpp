class Solution {
public:
    int n , m;
    bool f(int i, int j, string &s , string & t){
        if( i == n  ) return true;

        if(j == m ) return false;

        if(s[i] == t[j]) return f(i+1, j+1, s, t);
        return f(i , j+1, s, t);
    }
    bool isSubsequence(string s, string t) {
        n = s.size();
        m = t.size();
        return f(0, 0 , s ,t);
    }
};