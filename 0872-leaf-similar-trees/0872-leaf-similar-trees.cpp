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
    void solve(TreeNode* root,vector<int>& r)
    {
        if(root == NULL)
        return;
        if(root->left == NULL && root->right == NULL)
        {
            r.push_back(root->val);
        }
        solve(root->left,r);
        solve(root->right,r);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {
        vector<int> r1;
        solve(root1,r1);
        vector<int> r2;
        solve(root2,r2);
        int i=0;
        if(r1.size()!=r2.size())
        return false;
        for(i=0;i<r1.size();i++)
        {
            cout<<r1[i]<<endl<<r2[i]<<" ";
            if(r1[i]!=r2[i])
            return false;
        }
        
        return true;
    }
};