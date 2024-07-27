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
    // Mapping function to link child nodes to their parents
    void mapping(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mp) {
        if (root == NULL) return;
        if (root->left) {
            mp[root->left] = root;
            mapping(root->left, mp);
        }
        if (root->right) {
            mp[root->right] = root;
            mapping(root->right, mp);
        }
    }
    
    
    void solve(TreeNode* node, int k, vector<int>& ans, unordered_map<TreeNode*, TreeNode*>& mp, unordered_set<TreeNode*>& visited) 
    {
        if (node == NULL || visited.count(node) || k < 0) return;

        visited.insert(node);

        if (k == 0) 
        {
            ans.push_back(node->val);
            return;
        }
        
        solve(node->left, k - 1, ans, mp, visited);
        solve(node->right, k - 1, ans, mp, visited);
        solve(mp[node], k - 1, ans, mp, visited);    
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mp; // Mapping child nodes to parent nodes
        mapping(root, mp);
        
        vector<int> ans;
        unordered_set<TreeNode*> visited; 
        
        solve(target, k, ans, mp, visited);
        
        return ans;
    }
};
