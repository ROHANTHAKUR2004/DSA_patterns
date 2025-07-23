class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& pre) {
        int n = num;
        unordered_map<int, vector<int>> adj;

        vector<int> indgree(n , 0);
        for(vector<int> it : pre){

            int u = it[1];
            int v = it[0];

            adj[u].push_back(v);
            indgree[v]++;
        }

        queue<int> q;

        for(int i=0; i< n; i++){
            if(indgree[i] == 0) q.push(i);
        }

        int count = 0;

        while(!q.empty()){

            int node = q.front();
            q.pop();
            count++;

            for(auto it : adj[node]){
                indgree[it]--;

                if(indgree[it] == 0) q.push(it);
            }


        }
        if(count ==n) return true;
        return false;
    }
};