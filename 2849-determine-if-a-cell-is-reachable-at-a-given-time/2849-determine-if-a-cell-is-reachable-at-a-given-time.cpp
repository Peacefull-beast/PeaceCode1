class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) 
    {
        int dx = abs(sx-fx);
        int dy = abs(sy-fy);
        
        int d = min(dx,dy) + abs(dx-dy);
        if(d == 0 && t == 1)
            return false;
        if(t >= d)
            return true;
        else return false;
    }
};