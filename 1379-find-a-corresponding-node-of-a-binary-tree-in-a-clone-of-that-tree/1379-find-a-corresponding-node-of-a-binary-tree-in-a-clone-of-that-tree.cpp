/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* solve(TreeNode* cloned, TreeNode* target) {
        if (cloned == NULL) 
            return NULL;
        if (cloned->val == target->val) 
            return cloned;

        TreeNode* leftResult = solve(cloned->left, target);
        if (leftResult != NULL) 
            return leftResult;

        return solve(cloned->right, target);
    }

    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return solve(cloned, target);
    }
};
