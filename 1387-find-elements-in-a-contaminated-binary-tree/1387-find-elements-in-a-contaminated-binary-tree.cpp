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
class FindElements {
public:
    unordered_set<int>vis;
    void solve(TreeNode* root)
    {
        if(root == NULL)
            return;

        int x = root->val;
        if(root->left != NULL)
        {
            vis.insert(2*x +1);
            root->left->val = 2*x+1;
            solve(root->left);
        }
        if(root->right != NULL)
        {
            vis.insert(2*x +2);
            root->right->val = 2*x + 2;
            solve(root->right);
        }

        return;
    }
    FindElements(TreeNode* root) 
    {
        if(root)
        {
            vis.insert(0);
            root->val = 0;
            solve(root);
        }

        
    }
    
    bool find(int target) {
        if(vis.find(target) == vis.end())
        return false;
        return true;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */