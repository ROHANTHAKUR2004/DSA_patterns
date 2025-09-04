class Solution {
public:

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, vector<TreeNode*>> adj;

        if(!root) return {};

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            int sz = q.size();
            while(sz--){

                TreeNode* node = q.front();

                q.pop();

                if(node->left){
                    adj[node->left].push_back(node);
                    adj[node].push_back(node->left);
                    q.push(node->left);
                }
                 if(node->right){
                    adj[node->right].push_back(node);
                    adj[node].push_back(node->right);
                    q.push(node->right);
                }
            }
        }
         
        unordered_set<TreeNode*> visit;
        visit.insert(target);
        q.push(target);
      

        while(k--){
            int sz = q.size();
            while(sz--){
                TreeNode* node = q.front();
                q.pop();
                for(auto it : adj[node]){
                    if(!visit.count(it)){
                        visit.insert(it);
                        q.push(it);
                    }
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            TreeNode* n = q.front();
            q.pop();
            ans.push_back(n->val);
        }
        return ans;
    }
};