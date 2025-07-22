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
   bool f(TreeNode* root , TreeNode* rt){
       
       if(!root && !rt) return true;

       if(!root || !rt) return false;

       if(root->val != rt->val ) return false;

       return f(root->left, rt->right) && f(root->right, rt->left);
   }
    bool isSymmetric(TreeNode* root) {
        
        return f(root->left, root->right);
    }
};