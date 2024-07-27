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
    int ans = 0;
    
    
    void solve(TreeNode* root, int currentSum) {
        if (root == NULL)
            return;
        
        
        currentSum = (currentSum << 1) | root->val;
        
        
        if (root->left == NULL && root->right == NULL) {
            ans += currentSum;
            return;
        }
        
        
        solve(root->left, currentSum);
        solve(root->right, currentSum);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        solve(root, 0);
        return ans;
    }
};
