class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int x=prices.size()-1;
        if(x==0)
        return 0;
        int temp=prices[x]-prices[x-1];
        int c=max(prices[x-1],prices[x]);
        int ans=temp;
        for(int i=x-2;i>=0;i--)
        {
            temp=c-prices[i];
            if(temp>ans)
            ans=temp;
            c=max(c,prices[i]);
        }
        if(ans<0)
        return 0;
        return ans;
    }
};