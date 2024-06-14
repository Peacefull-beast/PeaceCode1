class Solution {
public:
    unordered_map<int, int> memo;
    
    
    int nextIndex(vector<int>& days, int currentIndex, int nextDay) 
    {
        while (currentIndex < days.size() && days[currentIndex] < nextDay) 
        {
            currentIndex++;
        }
        return currentIndex;
    }
    
    
    int solve(vector<int>& days, vector<int>& costs, int index) 
    {
        if (index >= days.size())
            return 0;
        
        if (memo.find(index) != memo.end())
            return memo[index];
        
        
        int d1 = costs[0] + solve(days, costs, nextIndex(days, index, days[index] + 1));
        
        
        int d7 = costs[1] + solve(days, costs, nextIndex(days, index, days[index] + 7));
        
        
        int d30 = costs[2] + solve(days, costs, nextIndex(days, index, days[index] + 30));
        
        memo[index] = min({d1, d7, d30});
        return memo[index];
    }



    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return solve(days, costs, 0);
    }
};
