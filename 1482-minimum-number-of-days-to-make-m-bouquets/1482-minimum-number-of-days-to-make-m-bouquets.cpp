class Solution {
public:
    bool posible(vector<int>& arr, int day, int r, int b)
    {
        int cnt = 0;
        int ans = 0;
        for(auto i : arr)
        {
            if(i < day)
                cnt++;
            
            else
            {
                ans += (cnt / b);
                cnt = 0;
            }
        }
        
        ans += (cnt/b );
        return ans >= r;
            
    }
    
    int minDays(vector<int>& arr, int r, int b) 
    {
        long long val = r * 1ll * b *1ll;
        if(val > arr.size())
            return -1;
        
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        for(auto i : arr)
        {
            maxi = max(i, maxi);
            mini = min(i, mini);
        }
        
        int low = mini; 
        int high = maxi;
        
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(posible(arr, mid, r, b))
                high = mid - 1;
            
            else
                low = mid + 1;
            
        }
        
        return low-1;
    }
};