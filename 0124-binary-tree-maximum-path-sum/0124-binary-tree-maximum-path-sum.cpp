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
    int findMaxPathSum(TreeNode* node, int &sum) {
        if (node == nullptr) 
            return 0;

        
        int leftMax  = max(0, findMaxPathSum(node->left,  sum)); 
        int rightMax = max(0, findMaxPathSum(node->right, sum));

        
        int currentValue = node->val;

        
        sum = max(sum, leftMax + rightMax + node->val);

        
        return max(leftMax, rightMax) + node->val; 
    }

    int maxPathSum(TreeNode* root) 
    {
        int sum = INT_MIN;  
        findMaxPathSum(root, sum);  
        return sum;  
    }
};