class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) 
    {
        vector<int>deg(n,0);
        unordered_map<int,vector<int>>mp;
        vector<int>dp(n,0);    
            
        for(auto rel : relations)
        {
            int u = rel[0]-1;
            int v = rel[1]-1;
            
            mp[u].push_back(v);
            
            deg[v]++;
        }
        
        
        queue<int>q;
        for(int i=0; i<n; i++)
        {
            if(deg[i] == 0)
            {
                q.push(i);
                dp[i] = time[i];
            }
        }
        
        while(!q.empty())
        {
            int sz = q.size();
            int t = 0; 
            while(sz--)
            {
                int front = q.front();
                q.pop();
                
                for(auto v:mp[front])
                {
                    dp[v] = max(dp[v], dp[front]+time[v]);
                    deg[v]--;
                    if(deg[v] == 0)
                        q.push(v);
                }
   
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};