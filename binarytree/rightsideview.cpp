class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};

        vector<int> ans;

        queue<TreeNode*> q;

        q.push(root);
        while(!q.empty()){

            int size = q.size();

            for(int i=0; i< size; i++){

                 TreeNode* node = q.front();
                 q.pop();

                if(i==0){
                    ans.push_back(node->val);
                }

                if(node->right) q.push(node->right);
                if(node->left) q.push(node->left);
            }
        }

        return ans;
    }
};