class Solution {
public:
    bool dfs(vector<int>& arr, int start, vector<int>& vis)
    {
        if(arr[start] == 0)
            return true;
        
        
        vis[start] = 1;
        int jl = start - arr[start];
        int jr = start + arr[start];
        
        if(jl >= 0 && jl < arr.size() && vis[jl] == 0)
             if(dfs(arr, jl, vis))
                 return true;
        if(jr >= 0 && jr < arr.size() && vis[jr] == 0)
            if(dfs(arr, jr, vis))
                return true;
        
        return false;
    }
    bool canReach(vector<int>& arr, int start)
    {
        int n = arr.size();
        
        vector<int>vis(n,0);
        
        
        return dfs(arr, start, vis);
        
        
        
    }
};