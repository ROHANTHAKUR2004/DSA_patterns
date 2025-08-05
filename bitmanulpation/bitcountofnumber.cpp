class Solution {
public:
   int f(int num){
       int count = 0;

       while(num != 0){  
           if(num & 1){
                count++; 
            }    
            num >>= 1  ;  
       }
       return count;
   }
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        ans[0] = 0;

        for(int i=1; i<=n; i++){
            int bitcount = f(i);

            ans[i] = bitcount;

        }
        return ans;
    }
};