class Solution {
public:
    int maxCoins(vector<int>& piles) 
    {
        sort(piles.begin(), piles.end());
        int n = piles.size();
        int ans = 0;
        int cnt = 0;
        for(int i = n-2; i>=0; i-=2)
        {
            ans += piles[i];
            cnt++;
            if(cnt == n/3)
                break;
        }
        
        return ans;
    }
};