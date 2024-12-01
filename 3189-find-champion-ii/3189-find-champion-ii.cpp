class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) 
    {
        unordered_map<int,vector<int>>mp;
        vector<int>deg(n,0);
        for(auto e : edges)
        {
            int u = e[0];
            int v = e[1];
            deg[v]++;
        }

        queue<int>q;
        for(int i=0; i<n; i++)
        {
            if(deg[i] == 0)
                q.push(i);
        }
        if(q.size() == 1)
        return q.front();
        else
        return -1;
    }
};