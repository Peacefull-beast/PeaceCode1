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
    int cnt = 0 ;
    void solve(TreeNode* node, int path)
    {
        if(node != nullptr)
        {
            path = (path ^ (1 << node->val));
            if(node->left == NULL && node->right == NULL)
            {
                if((path & (path-1)) == 0)
                    cnt++; 
            }
            solve(node->left, path);
            solve(node->right, path);
        }

    }
    int pseudoPalindromicPaths (TreeNode* root) 
    {
        
        solve(root, 0);
        return cnt;
    }
};