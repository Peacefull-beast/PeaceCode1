class Solution {
public:
    bool isPathCrossing(string path) 
    {
        set<pair<int,int>> x;
        
        pair<int,int>cp = {0,0};
        x.insert(cp);
        for(auto p : path)
        {
            if(p == 'N')
                cp = {cp.first+1,cp.second};
            else if(p == 'S')
                cp = {cp.first-1,cp.second};
            else if(p == 'E')
                cp = {cp.first,cp.second+1};
            else if(p == 'W')
                cp = {cp.first,cp.second-1};
            
            if(x.find(cp) == x.end())
                x.insert(cp);
            else
                return true;
            
        }
        return false;
    }
};