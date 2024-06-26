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
    void ino(TreeNode* root, vector<TreeNode*>& order)
    {
        if(root == NULL)
            return;
        ino(root->left, order);
        order.push_back(root);
        ino(root->right, order);
    }
    
    TreeNode* bst(vector<TreeNode*>& order, int l, int r)
    {
        if(l > r)
            return NULL;
        int mid = (l+r)/2;
        TreeNode* root = order[mid];
        root->left = bst(order, l, mid-1);
        root->right = bst(order, mid+1,r);
        
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) 
    {
        vector<TreeNode*> order;
        ino(root, order);
        return bst(order, 0, order.size()-1);
    }
};