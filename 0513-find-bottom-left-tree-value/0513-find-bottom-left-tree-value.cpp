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
    pair<int,int> solve(TreeNode* root)
    {
        if(root == NULL)
            return {0,0};
        
        if(root->left == NULL && root->right == NULL)
            return {root->val, 1};
        
        pair<int,int>left = solve(root->left);
        pair<int,int>rght = solve(root->right);
        
        if(rght.second > left.second)
            return {rght.first, rght.second+1};
        else
            return {left.first, left.second+1};
        
    }
    int findBottomLeftValue(TreeNode* root) 
    {
        return solve(root).first;
    }
};