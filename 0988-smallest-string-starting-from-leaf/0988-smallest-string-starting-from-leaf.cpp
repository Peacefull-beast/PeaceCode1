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
    
    void dfs(TreeNode* root, string &s, string &ans)
    {
        if(root == NULL)
            return;
        s+=('a' + root->val);
        
         
        if(root->left == NULL  && root->right == NULL)
        {
            reverse(s.begin(),s.end());
            ans = (ans.empty()) ? s : min(ans, s);
            reverse(s.begin(),s.end());           
        }
        dfs(root->left, s, ans);
        dfs(root->right, s, ans);
        
        s.pop_back();
        
        return;
    }
    string smallestFromLeaf(TreeNode* root) {
        string s = "";
        string ans = "";
        dfs(root, s, ans);
        return ans;
    }
};