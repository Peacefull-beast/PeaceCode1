class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) 
    {
        int  cr_time = 0;
        long long wt_time = 0;
        
        for(auto time : customers)
        {
            if(cr_time <= time[0])
                cr_time =   time[0];
            int prep = cr_time + time[1];
            cr_time = prep;
            
            wt_time += (prep - time[0]);
        }
        return (wt_time*(1.0))/customers.size();
    }
};