class Solution {
public:
    bool canPlaceFlowers(vector<int>& flower, int n) {
        int m = flower.size();
        int count = 0;

        for(int i = 0; i < m; i++){   
            if(flower[i] == 0){
                bool leftEmpty = (i == 0) || (flower[i-1] == 0);
                bool rightEmpty = (i == m-1) || (flower[i+1] == 0);

                if(leftEmpty && rightEmpty){
                    count++;
                    flower[i] = 1;   
                }
            }
        }
        return count >= n; 
    }
};
