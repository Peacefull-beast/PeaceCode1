class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>::iterator it1=intervals.begin();
        sort(intervals.begin(),intervals.end());
        for(int i=1;i<intervals.size();i++)
        {
            vector<vector<int>>::iterator it1=intervals.begin()-1+i;
            if(intervals[i-1][1]>=intervals[i][0])
            {
                intervals[i][0]=intervals[i-1][0];
                intervals[i][1]=max(intervals[i][1],intervals[i-1][1]);
                intervals.erase(it1);
                i--;
            } 
            
        }
        return intervals;
        
    }
};