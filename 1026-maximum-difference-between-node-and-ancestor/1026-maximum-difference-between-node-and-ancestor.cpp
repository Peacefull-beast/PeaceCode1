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
    int ans = INT_MIN;
    void solve(TreeNode *root, pair<int,int> values)
    {
        if(root == NULL)
            return;
        else if(root->left == NULL && root->right == NULL)
            ans = max(ans, abs(values.first - values.second));
        else
        {
            if(root->left != NULL)
                solve(root->left, {max(values.first, root->left->val), min(values.second, root->left->val)});
            if(root->right != NULL)
                solve(root->right,{max(values.first, root->right->val), min(values.second, root->right->val)});
        }  
        
        
    }
    int maxAncestorDiff(TreeNode* root) 
    {
        solve(root, {root->val, root->val});
        return ans;
    }
};