class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        
        auto cmp = [](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        };
        sort(points.begin(),points.end(), cmp);
        int pos = points[0][1];
        int cnt = 1;
        for(int i= 0 ; i<points.size(); i++)
        {
            if(points[i][0] <= pos)
                continue;
            pos = points[i][1];
            cnt++;
        }
        
        return cnt;
        
    }
};