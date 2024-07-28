class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& edges) 
    {
        unordered_map<int, vector<int>>mp;
        
        for(auto e : edges)
        {
            int u = e[0];
            int v = e[1];
            
            mp[u].push_back(v);
            mp[v].push_back(u);
            
        }
        
        int maxRank = INT_MIN;
        for(int i=0; i<n; i++)
        {
            int rank = 0;
            for(int j=i+1;j<n; j++)
            {
                int i_rank = mp[i].size();
                int j_rank = mp[j].size();
                
                rank = i_rank + j_rank;
                
                vector<int>temp = mp[i];
                for(auto n:temp)
                {
                    if(n == j)
                    {
                        rank--;
                        break;
                    }
                }
                maxRank = max(rank, maxRank);
            }
        }
        
        return maxRank;
    }
};