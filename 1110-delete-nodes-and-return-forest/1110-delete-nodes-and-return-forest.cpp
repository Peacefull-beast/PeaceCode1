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
    TreeNode* delNode(TreeNode* root, unordered_set<int>st, vector<TreeNode* >&res)
    {
        if(root == NULL)
            return NULL;
        
         root->left = delNode(root->left, st, res);
        root->right = delNode(root->right, st, res);
        
        
        if(st.find(root->val) != st.end())
        {
            if(root->left != NULL) res.push_back(root->left);
            if(root->right != NULL) res.push_back(root->right);
            return NULL;
        }
        else
            return root;
        
    }
    
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int>st;
        for(auto num : to_delete)
            st.insert(num);
        
        vector<TreeNode* >res;
        delNode(root, st, res);
        if(st.find(root->val) == st.end())
            res.push_back(root);
        
        return res;
        
    }
};