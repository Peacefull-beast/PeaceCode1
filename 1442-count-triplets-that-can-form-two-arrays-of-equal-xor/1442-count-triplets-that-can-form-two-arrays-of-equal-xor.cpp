class Solution {
public:
    int countTriplets(vector<int>& arr) 
    {
        int ans = 0;
        int n = arr.size();
        
        vector<int>pref(n+1, 0);
        
        unordered_map<int,int>sumofi; 
        unordered_map<int,int>cntofxor;
        sumofi[0] = 0;
        cntofxor[0] = 1;
        for(int k=1; k<=n; k++)
            pref[k] = pref[k-1]^arr[k-1];
        for(int k=1; k<=n; k++)
        {
            int x = pref[k];
            ans += k*cntofxor[x] - sumofi[x] - 1 * cntofxor[x];
            cntofxor[x]++;
            sumofi[x] += k;
        }
        return ans;
    }
};