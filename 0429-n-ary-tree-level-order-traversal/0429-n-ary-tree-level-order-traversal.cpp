/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) 
    {
        vector<vector<int>> ans;
        
        if (root == nullptr)  // Check if the root is null
            return ans;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())  // Removed the semicolon here
        {
            int sz = q.size();
            vector<int> temp;
            while(sz--)
            {
                Node* f = q.front();
                q.pop();
                temp.push_back(f->val);
                for(auto ch : f->children)
                {
                    q.push(ch);
                }
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};
