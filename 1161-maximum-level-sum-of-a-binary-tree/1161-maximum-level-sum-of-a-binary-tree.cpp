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
    int maxLevelSum(TreeNode* root) 
    {
//         int sum = 0;
//         int level = 1;
//         queue<TreeNode*>q;
        
//         q.push(root);
        
//         int temp = 0;
//         int l = 1;
//         while(!q.empty())
//         {
//             int sz = q.size();
            
//             temp = 0;
//             while(sz--)
//             {
//                 TreeNode* front = q.front();
//                 q.pop();
                
//                 if(front->left) q.push(front->left);
//                 if(front->right) q.push(front->right);
                
//                 temp += front->val;
                
//             }
            
//             if(temp > sum)
//             {
//                 sum = temp;
//                 level = l;
//             }
//             l++;
//         }
        
//         return level;
        queue<TreeNode*> q;
        q.push(root);
        int ma = 1;
        int sum = INT_MIN;
        int level = 1;
        
        while(!q.empty())
        {
            int size = q.size();
            int currSum = 0; 
            
            for(int i=0; i<size; i++)
            {
                currSum += q.front()->val;
                if(q.front()->left)q.push(q.front()->left);
                if(q.front()->right)q.push(q.front()->right);
                q.pop();
            }
            if(currSum > sum)
            {
                sum = currSum;
                ma = level;
            }
            level++;
        }
        return ma;
    }
};