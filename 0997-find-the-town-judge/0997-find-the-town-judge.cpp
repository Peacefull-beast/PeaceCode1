class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        vector<int>indeg(n+1, 0);
        vector<int>outdeg(n+1, 0);
        
        for(auto v : trust)
        {
            indeg[v[1]]++;
            outdeg[v[0]]++;
        }
        
        for(int i= 0;i<n; i++)
        {
            if(indeg[i+1] == n-1 && outdeg[i+1] == 0)
                return i+1;
        }
        return -1;
    }
};