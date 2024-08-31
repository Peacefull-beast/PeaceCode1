class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        if(amount == 0)
        return 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // n coins, amt to make
        pq.push({0,amount});

        unordered_set<int>vis;

        while(!pq.empty())
        {
            int coin = pq.top().first;
            int amt = pq.top().second;
            pq.pop();

            if(amt == 0)
            return coin;
            if(vis.find(amt) != vis.end())
            continue;
            vis.insert(amt);

            for(int i=0; i<coins.size(); i++)
            {
                if(amt < coins[i])
                continue;
                
                pq.push({coin+1, amt-coins[i]});
            }
        }
        return -1;
    }
};