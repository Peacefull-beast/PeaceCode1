#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> mp(26, -1);
        int ans = -1;
        for (int i = 0; i < s.length(); i++) {
            if (mp[s[i] - 'a'] == -1)
                mp[s[i] - 'a'] = i;
            else
                ans = max(ans, i - mp[s[i] - 'a'] - 1);
        }
        return ans;
    }
};
