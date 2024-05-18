
class Solution {
public:
    TreeNode* srt(TreeNode* root, int start) {
        if (!root) return NULL;
        if (root->val == start) return root;
        
        TreeNode* left = srt(root->left, start);
        if (left) return left;
        
        TreeNode* right = srt(root->right, start);
        if (right) return right;
        
        else return NULL;
    }
        
    void parent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mp) {
        if (!root) return;
        if (root->left) 
        {
            mp[root->left] = root;
            parent(root->left, mp);
        }
        if (root->right) 
        {
            mp[root->right] = root;
            parent(root->right, mp);
        }
    }
    
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> mp; // child -> parent map
        parent(root, mp);
        
        TreeNode* startNode = srt(root, start);
        if (!startNode) return 0;
        
        queue<TreeNode*> q;
        q.push(startNode);
        
        unordered_map<TreeNode*, bool> visited;
        visited[startNode] = true;
        
        int time = 0;
        
        while (!q.empty()) {
            int size = q.size();
            bool foundNewNode = false;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                // Process left child
                if (node->left && !visited[node->left]) {
                    q.push(node->left);
                    visited[node->left] = true;
                    foundNewNode = true;
                }
                
                // Process right child
                if (node->right && !visited[node->right]) {
                    q.push(node->right);
                    visited[node->right] = true;
                    foundNewNode = true;
                }
                
                // Process parent
                if (mp.find(node) != mp.end() && !visited[mp[node]]) {
                    q.push(mp[node]);
                    visited[mp[node]] = true;
                    foundNewNode = true;
                }
            }
            if (foundNewNode) {
                time++;
            }
        }
        
        return time;
    }
};
