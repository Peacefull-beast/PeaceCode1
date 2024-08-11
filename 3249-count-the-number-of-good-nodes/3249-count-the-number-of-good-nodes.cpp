class Solution {
public:
    int ans = 0;
    int solve(int root, int parent, unordered_map<int, vector<int>>&mp)
    {
        int size = 1;
        unordered_map<int,int>tr;
        
        vector<int>nbr = mp[root];
        
        for(int i=0;i<nbr.size(); i++)
        {
            if(nbr[i] != parent)
            {
                int sz = solve(nbr[i], root, mp);
                size += sz;
                tr[sz]++;
            }
        }
        if(tr.size() <= 1)
            ans++;
        
        return size;
        
    }
    int countGoodNodes(vector<vector<int>>& edges) 
    {
        unordered_map<int, vector<int>>mp;
        for(auto e:edges)
        {
            int u = e[0];
            int v = e[1];
            
            mp[u].push_back(v);
            mp[v].push_back(u);
         }
        
        solve(0, -1, mp);
        
        return ans;
        
    }
};