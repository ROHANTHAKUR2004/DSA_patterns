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
    bool f(TreeNode* root, int &targetSum , int sum){
          if(!root) return false;

          sum += root->val;
          if(!root->left && !root->right){
             if(sum == targetSum) return true;
             else return false;
          }
           return f(root->left, targetSum, sum ) ||  f(root->right, targetSum, sum );

         
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum =0;
        return f(root, targetSum, sum);
    }
};