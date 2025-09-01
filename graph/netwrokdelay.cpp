class Solution {
public:
    typedef pair<int, int> pp;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    
       unordered_map<int, vector<pp>> adj;
       for( auto i : times){
          int src = i[0];
          int dest = i[1];
          int w = i[2];

          adj[src].push_back({dest, w});
       }
     
       priority_queue<pp,vector<pp>,greater<pp>> pq;
       vector<int> result(n+1, INT_MAX);
       pq.push({k , 0});
       result[k] = 0;
       while(!pq.empty()){

          auto it = pq.top();

          int node = it.first;
          int weigh = it.second;

          pq.pop();

          for( auto n : adj[node]){
                 
                 int newnode = n.first;
                 int newweight = n.second;
                 if(weigh + newweight < result[newnode]){

                     result[newnode] = weigh + newweight;
                     pq.push({newnode , weigh+ newweight});
                 }   
          }
       }

       int ans = INT_MIN;

       for(int i=1 ; i<= n ;i++){
           ans = max(ans , result[i]);
       }
       
       return ans == INT_MAX ? -1 : ans;
    
    }
};