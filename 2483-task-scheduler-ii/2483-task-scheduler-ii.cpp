class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int time) 
    {
    unordered_map<int, long long> mp; 
    long long ctime = 1;              
    int n = tasks.size();       
    for(int i = 0; i < n; i++)
    {
        int prc = tasks[i];  

        if(mp.find(prc) == mp.end() || ctime - mp[prc] > time) 
        {
            mp[prc] = ctime;
            ctime++;
        }
        else
        {
            
            ctime = mp[prc] + time + 1;
            mp[prc] = ctime;    
            ctime++; 
        }
    }
    return ctime-1;
    }
};