class Solution {
public:
    int f(int num){
        int c= 0;

        while(num !=0){

            c += (num &1);

            num >>= 1;

        }
        return c;
    }
    int hammingWeight(int n) {
       return f(n);

       // return __builtin_pop_count(n);
    }
};