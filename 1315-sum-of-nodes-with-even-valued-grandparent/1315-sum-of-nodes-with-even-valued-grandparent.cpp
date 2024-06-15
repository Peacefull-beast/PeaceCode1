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
    void solve(TreeNode* root, int &sum)
    {
        if(root == NULL)
            return;
        
        if(root->val % 2 == 0)
        {
            TreeNode* head = root->left;
            if(head != NULL)
            {
                if(head->left != NULL)   sum += head->left->val;
                if(head->right != NULL)  sum += head->right->val;
            }
            head = root->right;
            if(head != NULL)
            {
                if(head->left != NULL)   sum += head->left->val;
                if(head->right != NULL)  sum += head->right->val;
            }
        }
        
        solve(root->left, sum);
        solve(root->right, sum);
        
        return;
  
    }
    int sumEvenGrandparent(TreeNode* root) 
    {
        int sum = 0;
        solve(root, sum);
        return sum;
    }
};