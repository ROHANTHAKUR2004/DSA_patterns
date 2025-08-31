class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& pre) {

        unordered_map<int, vector<int>> adj;

        vector<int> ind(num , 0);

        for(vector<int>& it : pre){

            int v  = it[0];
            int u = it[1];

            adj[u].push_back(v);
            ind[v]++;
        }

        queue<int> q;

        for(int i =0; i< num; i++){
            if(ind[i] == 0){
                q.push(i);
            }
        }
        int count = 0;
        while(!q.empty()){

            int src = q.front();
            q.pop();

            count++;

            for(auto it : adj[src]){
                ind[it]--;
                if(ind[it] == 0) q.push(it);
            }
        }
        if(count == num) return true;
        return false;
    }
};