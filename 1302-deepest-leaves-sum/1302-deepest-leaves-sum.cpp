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
    pair<int, int> solve(TreeNode* root) {
        if (root == NULL)
            return {0, 0};
        
        if(root->left == NULL && root->right == NULL)
            return {root->val, 1};
        
        pair<int, int> left = solve(root->left);  // {sum of deepest leaves, height}
        pair<int, int> right = solve(root->right); // {sum of deepest leaves, height}
        
        if (left.second > right.second)  // left height > right height
            return {left.first, left.second + 1};
        else if (left.second < right.second)  // right height > left height
            return {right.first, right.second + 1};
        else  // left height == right height
            return {left.first + right.first, left.second + 1};
    }
    
    int deepestLeavesSum(TreeNode* root) {
        return solve(root).first;
    }
};
