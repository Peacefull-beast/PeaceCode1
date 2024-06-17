class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        int ans = 0;
        int n = points.size();
        
        sort(points.begin(), points.end());
        
        for(int i=0; i<n;)
        {
            int cur = points[i][0];
            int max = cur+w;
            ans++;
            
            
            while(i<n && points[i][0] <= max)
                i++;
        }
        
        return ans;
    }
};