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
    unordered_map<int,int>mp;
    int ans(TreeNode* root)
    {
        if(root == NULL)
        return 0;

        int lsum = ans(root->left);
        int rsum = ans(root->right);

        int sum = lsum + rsum +root->val;
        mp[sum]++;

        return sum;    
    }
    vector<int> findFrequentTreeSum(TreeNode* root) 
    {
        vector<int>answer;
        priority_queue<pair<int,int>>pq;
        ans(root);
        for(auto i: mp)
        pq.push({i.second, i.first});

        int maxf = pq.top().first;

        while(!pq.empty() && pq.top().first == maxf)
        {
            answer.push_back(pq.top().second);
            pq.pop();
        }

        return answer;

    }
};