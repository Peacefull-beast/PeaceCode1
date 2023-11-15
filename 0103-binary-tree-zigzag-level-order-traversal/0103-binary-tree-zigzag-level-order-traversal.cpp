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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }

        int i = 1;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> temp;
        vector<vector<int>> ans;

        while (!q.empty()) {
            int levelSize = q.size();

            for (int j = 0; j < levelSize; ++j) {
                TreeNode* front = q.front();
                q.pop();

                if (i % 2 == 0) {
                    temp.insert(temp.begin(), front->val);
                } else {
                    temp.push_back(front->val);
                }

                if (front->left) {
                    q.push(front->left);
                }

                if (front->right) {
                    q.push(front->right);
                }
            }

            ans.push_back(temp);
            temp.clear();
            i++;
        }

        return ans;
    }
};