class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) 
    {
        int time = INT_MIN;
        for(auto r : right)
            time = max(time, n-r);
        for(auto l: left)
            time = max(time, l);
        
        return time;
        
    }
};