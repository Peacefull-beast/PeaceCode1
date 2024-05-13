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
    int fn(TreeNode* root, int sum, int ans)
    {
        if(root == NULL)
            return 0;
        sum = sum*10 + root->val;
        if(root->left == NULL && root->right == NULL)
            return (ans+=sum);
        int lftsum = fn(root->left, sum, ans);
        int rhtsum = fn(root->right, sum, ans);
        return lftsum+rhtsum;
    }
    int sumNumbers(TreeNode* root) 
    {
        int sum = 0;
        int ans = 0;
        return fn(root, sum,ans);
    }
};