class Solution {
public:
    int ans = 0;

    void solve(TreeNode* root, int maxi) {
        if (root == NULL)
            return;
        
        if (root->val >= maxi)
            ans++;
        
        maxi = max(maxi, root->val);
        
        if (root->left) solve(root->left, maxi);
        if (root->right) solve(root->right, maxi);
    }

    int goodNodes(TreeNode* root) {
        solve(root, INT_MIN);
        return ans;
    }
};