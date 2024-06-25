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
    int bsearch(int target, vector<int>&o)
    {
        int low = 0;
        int high = o.size()-1;
        while(low <= high)
        {
            int mid = (low+high)/2;
            if(target == o[mid])
                return mid;
            if(target > o[mid])
                low = mid+1;
            else
                high = mid-1;
        }
        
        return -1;
        
    }
    void solve(TreeNode* root, vector<int>& order, vector<int>& psum)
    {
        if(root == NULL)
            return;
        int ind = bsearch(root->val, order);
        root->val = psum[ind];
        solve(root->left,order,psum);
        solve(root->right,order,psum);
    }
    void ino(TreeNode* root, vector<int>& order)
    {
        if(root == NULL)
            return;
        ino(root->left, order);
        order.push_back(root->val);
        ino(root->right, order);
        
    }
    TreeNode* bstToGst(TreeNode* root) 
    {
        vector<int>order;
        ino(root, order);
        
        int sum = 0;
        int n=order.size();
        vector<int>psum(n, 0);
        
        for(int i=n-1; i>=0; i--)
        {
            sum+=order[i];
            psum[i]=sum;
        }
        solve(root,order,psum);
        
        return root;

    }
};