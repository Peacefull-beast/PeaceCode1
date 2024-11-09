class Solution {
public:
    long long maximumTotalSum(vector<int>& h) 
    {
        sort(h.begin(), h.end());
        int i = h.size()-1;
        long long sum = 0;
        int cnt = INT_MAX;
        while(i >= 0)
        {
            cnt = min(cnt-1, h[i]);
            if(cnt == 0)
            return -1;
            sum += cnt;
            i--;
        }
        return sum;
    }
};