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
    #define ll long long
    long long kthLargestLevelSum(TreeNode* root, int k) 
    {
        priority_queue<ll, vector<ll>>pq;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            int sz = q.size();
            ll sum = 0;

            while(sz--)
            {
                auto root = q.front();
                q.pop();

                sum += root->val;

                if(root->left) q.push(root->left);
                if(root->right) q.push(root->right);

            }


            pq.push(sum);
        }

        while (k > 1 && !pq.empty()) {
            pq.pop();
            k--;
        }

        return pq.empty() ? -1 : pq.top();
    }
};