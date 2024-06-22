class Solution {
public:
    int totalFruit(vector<int>& f) {
        int i = 0;
        int j = 0;
        int len = 0;
        int ans = 0;
        unordered_map<int, int>mp;
        
        while(j < f.size())
        {
            mp[f[j]]++;
            while(mp.size() > 2)
            {
                mp[f[i]]--;
                if(mp[f[i]] == 0)
                    mp.erase(f[i]);
                
                i++;
            }
            len = (j - i + 1);
            ans = max(ans, len);
            j++;
        }
        
        return ans;
    }
};