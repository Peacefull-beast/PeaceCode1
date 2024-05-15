class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) 
    {
        int time = 0;
        for(int i = 0; i<tickets.size(); i++)
        {
            if(i < k)
                time = time + min(tickets[i], tickets[k]);
            if(i == k)
                time = time + tickets[k];
            if(i > k)
                time = time + min(tickets[i], tickets[k] -1);
        }
        
        return time;
        
    }
};