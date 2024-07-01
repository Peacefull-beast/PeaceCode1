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
    vector<int> largestValues(TreeNode* root) 
    {
        vector<int> ans;
        
        int maxi = INT_MIN;
        
        queue<TreeNode*>q;
        if(root) q.push(root);
        
        while(!q.empty())
        {
            int sz = q.size();
            while(sz != 0)
            {
                TreeNode* f = q.front();
                q.pop();
                
                maxi = max(maxi, f->val);
                if(f->left)  q.push(f->left);
                if(f->right)  q.push(f->right);
                sz--;
            }
            
            ans.push_back(maxi);
            maxi = INT_MIN;
        }
        
        return ans;
        
    }
};