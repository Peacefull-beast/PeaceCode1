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
    void dfs (TreeNode* root, int curr, int val, int depth)
    {
        if(root == NULL)
            return;
        if(curr == depth - 1 )
        {
            TreeNode* newl = new TreeNode(val);
            newl->left = root->left;
            root->left = newl;
            TreeNode* newr = new TreeNode(val);
            newr->right = root->right;
            root->right = newr;
            
            return;
        }
        dfs(root->left, curr+1, val, depth);
        dfs(root->right, curr+1, val, depth);
        return;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) 
    {
        if(depth == 1)
        {
            TreeNode* temp = new TreeNode(val);
            temp->left = root;
            return temp;
        }
        
        dfs(root, 1, val, depth);
        
        return root;
    }
};