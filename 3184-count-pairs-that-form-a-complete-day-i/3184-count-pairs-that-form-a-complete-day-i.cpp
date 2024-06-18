class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        int ans = 0;
        unordered_map<int, int> mp;

        // Count the frequency of each hour % 24
        for (int hour : hours) {
            mp[hour % 24]++;
        }

        // Iterate over the map to find pairs
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            int h1 = it->first;
            int f1 = it->second;

            // Handle the case where the same hour can form a complete day pair
            if (h1 == 0 || h1 == 12) {
                ans += (f1 * (f1 - 1)) / 2; // nC2 pairs within the same group
                mp[h1] = 0; // Mark as processed
            } else {
                int h2 = 24 - h1;
                if (mp.find(h2) != mp.end()) {
                    int f2 = mp[h2];
                    ans += f1 * f2; // Count pairs between different groups
                    mp[h2] = 0; // Mark the pair's counterpart as processed
                    mp[h1] = 0; // Mark as processed
                }
            }
        }

        return ans;
    }
};
