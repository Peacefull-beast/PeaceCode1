class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) 
    {
        vector<int>deg(n,0);
        for(auto road:roads)
        {
            deg[road[0]]++;
            deg[road[1]]++;
        }
        sort(deg.begin(),deg.end());
        long long i = 1;
        long long ans = 0;
        for(auto city : deg)
        {
            ans += (city*i);
            i++;
        }
        return ans;
    }
};