class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
      
        unordered_map<int, vector<pair<int, int>>> mp;
        
        
        for (auto e : redEdges) 
        {
            int u = e[0];
            int v = e[1];
            mp[u].push_back({v, 0}); 
        }
        for (auto e : blueEdges) {
            int u = e[0];
            int v = e[1];
            mp[u].push_back({v, 1}); 
        }
        
        vector<int> ans(n, INT_MAX);
        ans[0] = 0;
        
        
        queue<pair<int, int>> q; // node, last color
        q.push({0, 0});
        q.push({0, 1}); 
        
        
        vector<vector<bool>> visited(n, vector<bool>(2, false));
        visited[0][0] = visited[0][1] = true;
        
        int dist = 0;
        
        
        while (!q.empty()) 
        {
            int sz = q.size();
            while (sz--) 
            {
                int node =  q.front().first;
                int color =  q.front().second;
                q.pop();
                
                for (auto nbr : mp[node]) 
                {
                    int nnode = nbr.first;
                    int ncolor = nbr.second;
                    
                    
                    if (ncolor == color || visited[nnode][ncolor])//same color or visited state
                        continue;
                    
                    visited[nnode][ncolor] = true;
                    q.push({nnode, ncolor});
                    ans[nnode] = min(ans[nnode], dist + 1);
                }
            }
            dist++;
        }
        
        for (int i = 0; i < n; i++) {
            if (ans[i] == INT_MAX) 
                ans[i] = -1;
            
        }
        
        return ans;
    }
};
