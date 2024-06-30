class Solution {
public:
    void solve(int node, unordered_map<int,vector<int>> &adj, bool &ans,vector<int>&vis,vector<int>&prnt)
    {    
          if(vis[node]==1 && prnt[node]==0){
                 return;
          }
          vis[node]=1;
          if(vis[node]==1 && prnt[node]==1){
              ans=false;
              return;
          } 
          prnt[node]=1;      
          for(int i=0; i<adj[node].size(); i++){
              solve(adj[node][i],adj,ans,vis,prnt);

          }  
          prnt[node]=0;
    }
    bool canFinish(int num, vector<vector<int>>& pre) 
    {
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<pre.size();i++)
            adj[pre[i][1]].push_back(pre[i][0]);
        
        vector<int> vis(num,0);
        vector<int> prnt(num,0);
        bool ans= true;
        for(int i=0;i<num;i++){
            if(vis[i]==0){
                solve(i,adj,ans,vis,prnt);
            }
        }
        return ans;
    }
};