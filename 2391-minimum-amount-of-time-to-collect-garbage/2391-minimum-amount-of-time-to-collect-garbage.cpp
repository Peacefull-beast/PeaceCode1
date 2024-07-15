class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int gg = -1;
        int gp = -1;
        int gm = -1;
        
        int n = garbage.size();
        int t = 0;
        for(int i = n-1; i>=0; i--)
        {
            t += garbage[i].size();
            for(auto g : garbage[i])
            {
                if(g == 'G' && gg == -1)
                    gg = i;
                else if(g == 'M' && gm == -1)
                    gm = i;
                else if(g == 'P' && gp == -1)
                    gp = i;
                
            }
        }
        
        for(int i = 0; i < gp; i++)
            t += travel[i];
        for(int i = 0; i < gm; i++)
            t += travel[i];
        for(int i = 0; i < gg; i++)
            t += travel[i];
        
        return t;
        
    }
}; 