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
    TreeNode *solve(TreeNode* root, int p,int q)
    {
        if(root == NULL)
            return NULL;
        if(root->val==p ||root->val==q)
            return root;
        TreeNode* lans= solve(root->left,p,q);
        TreeNode* rans= solve(root->right,p,q);
        if(lans== NULL && rans == NULL)
            return NULL;
        else if(lans != NULL && rans == NULL)
            return lans;
        else if(lans == NULL && rans != NULL)
            return rans;
        else 
            return root;
    
    }
    
    
    bool findPath(TreeNode* root, int target, string &path) {
        if (root == NULL) 
            return false;

        if (root->val == target) 
            return true;
        
        path += 'L';
        if (findPath(root->left, target, path)) 
            return true;
        
        path.pop_back();

        path += 'R';
        if (findPath(root->right, target, path)) 
            return true;
        
        path.pop_back();

        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) 
    {
        TreeNode* lca = solve(root, startValue, destValue);
        string pathToStart = "", pathToDest = "";

        
        findPath(lca, startValue, pathToStart);
        
        findPath(lca, destValue, pathToDest);

        
        for (char &c : pathToStart) {
            c = 'U';
        }

        return pathToStart + pathToDest;
    }
};