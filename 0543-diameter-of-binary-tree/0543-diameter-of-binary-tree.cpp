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
    int maxi;
    int height(TreeNode* root )
    {
        if(root == NULL)
            return 0;
        
        int l = height(root->left);
        int h = height(root->right);
        
        maxi = max(maxi, l+h);
        return max(l,h)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
        maxi = 0;
        height(root);
        return maxi;
         
    }
};