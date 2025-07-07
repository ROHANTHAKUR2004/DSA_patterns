class Solution {
public:
   // leftmaxarray
    vector<int> findleftmax( int &n ,vector<int>& height){
        vector<int> left(n);

        left[0] = height[0];

        for(int i=1 ; i<n ;i++){
            left[i] = max(left[i-1], height[i]);
        }
        return left;
    }

    //rightmaxarray
    vector<int> findrightmax( int &n ,vector<int>& height){
         vector<int> right(n);
       
          right[n-1] = height[n-1];
           for(int i= n-2; i>=0 ;i--){
             right[i] = max(right[i+1], height[i]);
         }

         return right;
    }


    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> leftmax = findleftmax(n, height);
        vector<int> rightmax = findrightmax(n, height);

        int sum  = 0;
        for(int i=0; i< n; i++){
            int h = min(leftmax[i], rightmax[i]) - height[i];
            sum += h;
        }
        return sum ;
    }
};