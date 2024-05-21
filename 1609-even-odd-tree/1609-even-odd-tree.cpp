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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> result;

        if (root == nullptr)
            return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel;

            for (int i = 0; i < levelSize; ++i)
            {
                TreeNode* node = q.front();
                q.pop();

                currentLevel.push_back(node->val);

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            result.push_back(currentLevel);
        }

        return result;
    }
    
    bool oddinc(vector<int> &v1)
    {
        if (v1[0] % 2 == 0)
            return false;
        for (int i = 1; i < v1.size(); i++)
        {
            if (v1[i] % 2 == 0)
                return false;
            if (v1[i] <= v1[i - 1])
                return false;
        }
        return true;
    }
    
    bool evendec(vector<int> &v1)
    {
        if (v1[0] % 2 != 0)
            return false;
        for (int i = 1; i < v1.size(); i++)
        {
            if (v1[i] % 2 != 0)
                return false;
            if (v1[i] >= v1[i - 1])
                return false;
        }
        return true;
    }
    
    bool isEvenOddTree(TreeNode* root) 
    {
        vector<vector<int>> level = levelOrder(root);
        for (int i = 0; i < level.size(); i++)
        {
            if (i % 2 == 0)
            {
                if (!oddinc(level[i]))
                    return false;
            }
            else
            {
                if (!evendec(level[i]))
                    return false;
            }
        }
        return true;
    }
};
