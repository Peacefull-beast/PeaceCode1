#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] != b[1] ? a[1] < b[1] : a[0] > b[0];
        });
        
        vector<int> ans;
        
        for (auto& interval : intervals) 
        {
            int s = interval[0];
            int e = interval[1];
            
            
            int count = 0;
            for (int i=ans.size()-1; i >= 0 && ans[i] >= s; --i)
            {
                ++count;
                if(count >= 2)
                    break;
            }
            
            
            if (count == 0) 
            {
                ans.push_back(e - 1);
                ans.push_back(e);
            } 
            else if (count == 1)
                ans.push_back(e);
        }
        
        return ans.size();
    }
};
