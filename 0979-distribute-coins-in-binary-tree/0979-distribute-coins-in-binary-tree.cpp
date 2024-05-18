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
    int stps = 0;
    int solve(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        int left = solve(root->left);
        int rght = solve(root->right);
        
        stps += abs(left)+abs(rght);
        return (root->val-1) + left + rght;
    }
    int distributeCoins(TreeNode* root) {
        int ans = solve(root);
        return stps;
    }
};