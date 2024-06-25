#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int solve(int ind, string& s, vector<int>& memo) {
        if (ind >= s.length()) return 1;
        if (s[ind] == '0') return 0;
        if (memo[ind] != -1) return memo[ind];
        
        
        int one = solve(ind + 1, s, memo);
        int two = 0;
        if (ind + 1 < s.length() && (s[ind] == '1' || (s[ind] == '2' && s[ind + 1] <= '6'))) {
            two = solve(ind + 2, s, memo);
        }
        
        memo[ind] = one + two;
        return memo[ind];
    }
    
    int numDecodings(string s) {
        vector<int> memo(s.length(), -1);
        return solve(0, s, memo);
    }
};
