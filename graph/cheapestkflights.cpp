class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        unordered_map<int, vector<pair<int,int>>> adj;

        for(vector<int> it : flights){

            int src = it[0];
            int dst = it[1];
            int wt = it[2];

            adj[src].push_back({dst, wt});
        }

        vector<int> price(n , INT_MAX);

        queue<pair<int,int>> q;

        q.push({src, 0});

        price[src] = 0;

        int level = 0;

        while(!q.empty() && level <= k){

            int sz = q.size();

            while(sz--){

                auto it  = q.front();
                q.pop();

                int sc = it.first;
                int p = it.second;

                for(auto it : adj[sc]){

                    int dt = it.first;
                    int pr = it.second;

                    if( p + pr < price[dt]){
                         price[dt] =  p + pr;
                         q.push({dt, p + pr});
                    }

                }

            }
            level++;
        }
        if(price[dst] == INT_MAX ) return -1;
        return price[dst];

    }
};