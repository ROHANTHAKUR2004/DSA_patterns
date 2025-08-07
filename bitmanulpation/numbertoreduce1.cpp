class Solution {
public:
    int numSteps(string s) {
        int n = s.size();

        int count = 0;
        int carry = 0;

        for(int  i = n-1; i>=1 ; i--){
             if(((s[i]- '0') + carry) % 2 == 1){ // odd h
                count += 2;
                carry = 1;
             }else { //even
               count++;
             }
        }
        return count + carry;
    }
};