class Solution {
public:

  int customupperbound(vector<int>&arr, int target){

    int l = 0;
    int r = arr.size() -1;

    int ans = arr.size();

    while(l <= r){

        int mid = l + (r-l)/2;

        if(arr[mid] > target) {
             ans = mid;
             r = mid -1;
        }else {
            l = mid + 1;
        }
    }
    return ans;   
  }

  int customlowerbound(vector<int>&arr, int target){

    int l = 0;
    int r = arr.size() -1;

    int ans = arr.size();

    while(l <= r){

        int mid = l + (r-l)/2;

        if(arr[mid] >= target) {
             ans = mid;
             r = mid -1;
        }else {
            l = mid + 1;
        }
    }
    return ans;   
  }



    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = flowers.size();
        int m = people.size();

        vector<int> start_time(n);
        vector<int> end_time(n);

        for(int i=0; i< n; i++){

            start_time[i] = flowers[i][0];
            end_time[i] = flowers[i][1];     
        }

        sort(start_time.begin(), start_time.end());
        sort(end_time.begin(), end_time.end());


        vector<int> ans;
        for(int i=0; i< m; i++){

            int time = people[i];

            // int ub = upper_bound(start_time.begin(), start_time.end(), time) - start_time.begin();

             //int lb = lower_bound(end_time.begin(), end_time.end(), time) - end_time.begin();

            int ub = customupperbound(start_time, time);

            int lb = customlowerbound(end_time, time);


            ans.push_back(ub-lb);

        }

        return ans;
    }
};