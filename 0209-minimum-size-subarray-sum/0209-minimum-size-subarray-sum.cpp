class Solution {
public:
    bool func(int mid, int k, vector<int>& v) {
        int n = v.size();
        int sum = 0;
        for (int i = 0; i < mid; i++) 
            sum += v[i];
        
        if (sum >= k) return true;

        for (int i = mid; i < n; i++) {
            sum += v[i] - v[i - mid];
            if (sum >= k) return true;
        }
        return false;
    }

    int minSubArrayLen(int t, vector<int>& v) {
        int n=v.size();
        int start = 0;
        int ans=0;
        int end = n;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(func(mid,t,v))
            {
                ans = mid;
                end = mid-1;
            }
            else start=mid+1;
        }
        return ans;
        
    }
};