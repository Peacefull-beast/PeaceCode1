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
    bool ans(TreeNode* root)
    {
        if(root->left == NULL && root->right == NULL)
        {
            if(root->val == 1)
                return true;
            else
                return false;
        }
        bool left = ans(root->left);
        bool right = ans(root->right);
        
        if(root->val == 2)
            return (left || right);
        else
            return (left && right);
    }
    bool evaluateTree(TreeNode* root) 
    {
         return ans(root);   
    }
};