class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) 
    {
        vector<double>mon;
        int n=dist.size();
        
        for(int i=0; i<n;i++)
            mon.push_back((dist[i]*(1.0))/speed[i]);
        
        
        sort(mon.begin(), mon.end());
        
        for(int i=0; i<n; i++)
            if(mon[i]-i <= 0)
                return i;
        
        return n;
    }
};