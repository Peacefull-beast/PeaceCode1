class Solution {
public:
    int maxDistToClosest(vector<int>& seats) 
    {
        int n = seats.size();
        int ans = 0;
        
        
        int i = 0;
        while(i < n && seats[i] == 0)
            i++;
        ans = i;  
        
       
        int lp = i;  
        for(; i < n; i++)
        {
            if(seats[i] == 1)
            {
                int dist = (i - lp) / 2;  
                ans = max(ans, dist);     
                lp = i;                   
            }
        }
        
    
        if(seats[n - 1] == 0)
        {
            ans = max(ans, n - 1 - lp); 
        }

        return ans;
    }
};
