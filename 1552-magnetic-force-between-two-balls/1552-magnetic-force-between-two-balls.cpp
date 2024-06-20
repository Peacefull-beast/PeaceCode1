class Solution {
public:
    bool isokay(int mid, vector<int>& position, int m)
    {
        int cnt = 1;
        int pid = 0;
        
        for(int i=1; i<position.size(); i++)
        {
            if(position[i] - position[pid] >= mid)
            {
                cnt++;
                pid = i;
            }
        }
        
        return cnt>=m;
    }
    
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        
        int l = 0;
        int r = *max_element(position.begin(), position.end());
        
        int ans = -1;
        
        while(l <= r)
        {
            int mid = (l + r)/2;
            if(isokay(mid, position, m))
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        
        return ans;
    }
};