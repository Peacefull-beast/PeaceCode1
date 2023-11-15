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
    bool issy(TreeNode* root1, TreeNode* root2)
    {
        if(root1 == NULL && root2 == NULL)
            return true;
        if(root1 == NULL && root2 != NULL)
            return false;
        if(root2 == NULL && root1 != NULL)
            return false;
        bool cond2 = true;
        bool cond3 = true;
        bool cond1=(root1->val == root2->val);
        if(root1->left != NULL && root2->right != NULL)
        cond2 = root1->left->val == root2->right->val;
        if(root2->left != NULL && root1->right != NULL)
        cond3 = root1->right->val == root2->left->val;
        bool cond5 = issy(root1->left, root2->right);
        bool cond6 = issy(root1->right, root2->left);
        if (cond1 && cond2 && cond3 && cond5 && cond6)
        return true;
        else return false;
    }
    bool isSymmetric(TreeNode* root) {
        return issy(root->left, root->right);
    }
};