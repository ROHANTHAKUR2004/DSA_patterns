class Solution {
public:
    vector<vector<int>> dir {{1, 0}, { 0, 1}, { -1, 0}, { 0 , -1}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n = image.size();
        int m = image[0].size();

        int originalcolor = image[sr][sc];

        if( originalcolor == color) return image;

        queue<pair<int,int>> q;

        q.push({sr, sc});

        image[sr][sc] = color;

        while(!q.empty()){

            int sz = q.size();

            while(sz--){
               
                auto it = q.front();
                q.pop();

                int row = it.first;
                int col = it.second;

                for(auto it : dir){
                    int newr = row +  it[0];
                    int newc = col +  it[1];

                    if(newr >= 0 && newc >= 0 && newr < n && newc < m && image[newr][newc] == originalcolor){
                        image[newr][newc] = color;
                        q.push({newr, newc});
                    }

                }
            }

        }

        return image;


    }
};