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
    int hieght(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int lans=hieght(root->left);
        int rans=hieght(root->right);
        return max(lans,rans)+1;
        
    }
    bool fun(TreeNode* root)
    {
        if(root==NULL)
            return true;
        int lh=hieght(root->left);
        int rh=hieght(root->right);
        if(abs(lh-rh)<=1)
            return true;
        else return false;
    }
    bool isBalanced(TreeNode* root)
    {
        if(root==NULL)
            return true;
         bool f1=isBalanced(root->left);
         bool f2=isBalanced(root->right);
         bool f3=fun(root);
        if(f1 && f2 && f3)
            return true;
        else
            return false;
    }
};