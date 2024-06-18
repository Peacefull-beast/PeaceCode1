class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long ans = 0;
        unordered_map<int, long long> mp;

        
        for (int hour : hours) {
            mp[hour % 24]++;
        }

        for (auto it = mp.begin(); it != mp.end(); ++it) {
            int h1 = it->first;
            long long f1 = it->second;

            
            if (h1 == 0 || h1 == 12) {
                ans += (f1 * (f1 - 1)) / 2; 
                mp[h1] = 0;
            } 
            else 
            {
                int h2 = 24 - h1;
                if (mp.find(h2) != mp.end()) 
                {
                    long long f2 = mp[h2];
                    ans += f1 * f2; 
                    mp[h2] = 0; // Mark the pair's counterpart as processed
                    mp[h1] = 0; // Mark as processed
                }
            }
        }

        return ans;

    }
};
