class Solution {
public:
   void dfs(int src, unordered_map<int,vector<int>> adj,  vector<int> &visited ){

       visited[src] = -1;

       for(auto it : adj[src]){
           if(!visited[it]){
                dfs(it, adj, visited);
           }
       }


   }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        unordered_map<int,vector<int>> adj;

        for(int i=0; i< n; i++){
             for(auto it : rooms[i]){
                 adj[i].push_back(it);
             }
        }

        vector<int> visited(n, 0);

         dfs(0, adj, visited);

         for(int i=0; i<n; i++){
             if(visited[i] != -1) return false;
         }

         return true;
    }
};