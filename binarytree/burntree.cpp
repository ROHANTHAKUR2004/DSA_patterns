/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
         if(!root) return 0;
        unordered_map<int, vector<int>> adj;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                
                TreeNode* node = q.front();
                q.pop();

                if(node->left){

                    adj[node->val].push_back(node->left->val);
                    adj[node->left->val].push_back(node->val);
                    q.push(node->left);

                }
                if(node->right){
                     adj[node->val].push_back(node->right->val);
                     adj[node->right->val].push_back(node->val);
                     q.push(node->right);
                }
            }
        }

            int level = 0;
            queue<int> pq;
            pq.push(start);
            unordered_set<int> st;
            st.insert(start);

            while(!pq.empty()){
                int sz = pq.size();

                while(sz--){

                    int node = pq.front();
                    pq.pop();

                    

                    for(auto it : adj[node]){
                        if(!st.count(it)){
                            st.insert(it);
                            pq.push(it);
                        }
                    }

                }
                level++;
            }
        return level-1;
    }
};