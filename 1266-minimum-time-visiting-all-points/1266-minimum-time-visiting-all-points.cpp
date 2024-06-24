class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) 
    {
        int res = 0;
        for(int i=1; i<points.size(); i++)
        {
            int h = abs(points[i][0] - points[i-1][0]);
            int v = abs(points[i][1] - points[i-1][1]);
            res += max(h,v);
        }
        
        return res;
    }
};