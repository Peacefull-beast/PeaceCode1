class Solution {
public:
    vector<int> merge(vector<int>&parent, vector<int>& child)
    {
        int n = parent.size();
        int m = child.size();
        int i = 0;
        int j = 0;
        
        vector<int>sortedList;
        
        while(i<n && j < m)
        {
            if(parent[i] < child[j])
            {
                while(i+1 < n && parent[i] == parent[i+1]) i++;
                sortedList.push_back(parent[i]);
                i++;
            }
            else if(parent[i] > child[j])
            {
                while(j+1 < m && child[j] == child[j+1]) j++;
                sortedList.push_back(child[j]);
                j++;
            }
            else
            {
                while(i+1 < n && parent[i] == parent[i+1]) i++;
                while(j+1 < m && child[j] == child[j+1]) j++;
                sortedList.push_back(child[j]);
                i++;
                j++;
            }
            
        }
        while(i < n)
        {
            while(i+1 < n && parent[i] == parent[i+1]) i++;
            sortedList.push_back(parent[i]);
                i++;
        }
        while(j < m)
        {
                while(j+1 < m && child[j] == child[j+1]) j++;
                sortedList.push_back(child[j]);
                j++;
        }
        return sortedList;
    }
    
    
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) 
    {
        unordered_map<int, vector<int>>sortedAnc;
        vector<int>deg(n,0);
        unordered_map<int,vector<int>>gr;
        for(auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            gr[u].push_back(v);
            deg[v]++;
        }
        
        queue<int>q;
        unordered_map<int,int>vis;
        for(int i=0;i<n;i++)
        {
            if(deg[i] == 0)
                q.push(i);
        }
        
        
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int node = q.front();
                q.pop();
                vector<int> anc =  sortedAnc[node];
                for(auto child: gr[node])
                {
                    deg[child]--;
                    vector<int>par = {node};
                    sortedAnc[child] = merge(sortedAnc[child], sortedAnc[node]);
                    
                    sortedAnc[child] = merge(sortedAnc[child],par);
                    if(deg[child] == 0)
                        q.push(child);
                }
                    
            }
        }
        vector<vector<int>>ans;
        for(int i=0;i<n;i++)
            ans.push_back(sortedAnc[i]);
        
        return ans;
    }
};