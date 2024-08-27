class TreeAncestor {
public:
    unordered_map<int,int>mp;
    vector<vector<int>>dp;
    int level; //node, k anc
    TreeAncestor(int n, vector<int>& parent) 
    {
        level = log2(n) + 1;
        dp.resize(n, vector<int>(level, -1));

        for (int i = 0; i < n; ++i) {
            dp[i][0] = parent[i]; 
        }

        
        for (int j = 1; j < level; ++j)
        {
            for (int i = 0; i < n; ++i) 
            {
                if (dp[i][j-1] != -1) 
                    dp[i][j] = dp[dp[i][j-1]][j-1];
                
            }
        }
    }

    
    
    int getKthAncestor(int node, int k) 
    {
        for (int j = 0; j < level; ++j) {
            if (k & (1 << j)) { // Check if the j-th bit of k is set
                node = dp[node][j];
                if (node == -1) break; // If we reach an ancestor that doesn't exist, return -1
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */