class Solution {
public:
    int finddays(vector<int>we, int c)
    {
        int d = 1; 
        int l = 0;
        
        for(auto w : we)
        {
            if(w + l > c)
            {
                d += 1;
                l = w;
            }
            else
                l += w;
        }
        return d;
    }
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        
        while(low <= high)
        {
            int mid = (low + high)/2;
            int nday = finddays(weights, mid);
            
            if(nday <= days)
                high = mid - 1;
            else
                low = mid + 1;
        }
        
        return low;
    }
};