class Solution {
public:
    long root_res = 0;
    
    
    int dfs(unordered_map<int, vector<int>>& mp, int c_node, int p_node, int d, vector<int>& cnt) {
        int t_cnt = 1;  
        root_res += d;  
        
        for (auto child : mp[c_node]) {
            if (child == p_node)  
                continue;
            
            t_cnt += dfs(mp, child, c_node, d + 1, cnt); 
        }
        cnt[c_node] = t_cnt;  
        return t_cnt; 
    }
    
    
    void dfss(unordered_map<int, vector<int>>& mp, int c_node, int p_node, vector<int>& result, vector<int>& cnt, int n) {
        for (int &child : mp[c_node]) {
            if (child == p_node) 
                continue;
            
            
            result[child] = result[c_node] - cnt[child] + (n - cnt[child]);
            
           
            dfss(mp, child, c_node, result, cnt, n);
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> mp;
        
        
        for (auto e : edges) {
            int u = e[0];
            int v = e[1];
            
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        
        vector<int> res(n, 0);  
        vector<int> cnt(n, 0);  
        
        
        dfs(mp, 0, -1, 0, cnt);
        res[0] = root_res;
        
        
        dfss(mp, 0, -1, res, cnt, n);
        
        return res;
    }
};
