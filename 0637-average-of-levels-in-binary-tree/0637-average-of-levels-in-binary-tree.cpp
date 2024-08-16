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
    vector<double> averageOfLevels(TreeNode* root) 
    {
        vector<double>ans;
        queue<TreeNode*>q;
        
        q.push(root);
        
        while(!q.empty())
        {
            int sz = q.size();
            long long temp = 0;
            int num = sz;
            while(sz--)
            {
                TreeNode* f = q.front();
                q.pop();
                
                
                temp += f->val;
                if(f->left)q.push(f->left);
                if(f->right)q.push(f->right);
            }
            ans.push_back(temp*1.0/num);
        }
        return ans;
    }
};