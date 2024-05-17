class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>> &arr)
    {
        vector<vector<int>>ans;
        ans.push_back(arr[0]);


        for(int i = 1; i<arr.size(); i++)
        {
            
            int psrt = ans.back()[0];
            int pend = ans.back()[1];
            
            
            int csrt = arr[i][0];
            int cend = arr[i][1];
            
            if(csrt <= pend)
                ans.back()[1] = max(cend, pend);
            else
                ans.push_back(arr[i]);
        }
        return ans;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        return merge(intervals);
    }
};