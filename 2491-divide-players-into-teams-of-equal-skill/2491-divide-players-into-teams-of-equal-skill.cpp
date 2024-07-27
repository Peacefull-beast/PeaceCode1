#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long sum = 0;
        for (auto s : skill)
            sum += s;

        int n = skill.size();
        
        
        if ((sum * 2) % n != 0)
            return -1;

        int targetSum = (sum * 2) / n;
        unordered_map<int, int> mp;
        long long ans = 0;

        for (auto t : skill) {
            int complement = targetSum - t;
            if (mp[complement] > 0) {
                ans += t * complement; 
                mp[complement]--; 
            } else {
                mp[t]++; 
            }
        }

        
        for (auto& [key, value] : mp) {
            if (value != 0)
                return -1;
        }

        return ans;
    }
};
