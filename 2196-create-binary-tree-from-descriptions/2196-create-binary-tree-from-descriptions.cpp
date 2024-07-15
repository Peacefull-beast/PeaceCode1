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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) 
    {
        unordered_map<int, TreeNode*>map;
        unordered_set<int>child;
        for(auto d : descriptions)
        {
            int p = d[0];
            int c = d[1];
            int s = d[2];
            
            child.insert(c);
            
            if (map.find(p) == map.end()) 
            map[p] = new TreeNode(p);
        
            if (map.find(c) == map.end()) 
            map[c] = new TreeNode(c);
        
            if (s == 1) 
            map[p]->left = map[c];
            else 
            map[p]->right = map[c];
            
        }
        
        int root = -1;
        for (auto& arr : descriptions) 
        {
            if (child.find(arr[0]) == child.end())
            {
                root = arr[0];
                break;
            }
        }
        
        return map[root];
        
        
    }
};