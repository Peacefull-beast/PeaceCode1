class Solution {
public:
    vector<vector<int>> memo;
    
    int solve(string& s1, string& s2, int i1, int i2) {
        if (i1 == s1.length() && i2 == s2.length())
            return 0;
        
        if (i1 == s1.length()) {
            int sum = 0;
            for (int i = i2; i < s2.length(); ++i)
                sum += s2[i];
            return sum;
        }
        
        if (i2 == s2.length()) {
            int sum = 0;
            for (int i = i1; i < s1.length(); ++i)
                sum += s1[i];
            return sum;
        }

        if (memo[i1][i2] != -1)
            return memo[i1][i2];
        
        int db = INT_MAX;
        if (s1[i1] == s2[i2])
            db = solve(s1, s2, i1 + 1, i2 + 1);
        
        int d1 = s1[i1] + solve(s1, s2, i1 + 1, i2);
        int d2 = s2[i2] + solve(s1, s2, i1, i2 + 1);
        
        memo[i1][i2] = min({db, d1, d2});
        return memo[i1][i2];
    }

    int minimumDeleteSum(string s1, string s2) {
        memo = vector<vector<int>>(s1.length(), vector<int>(s2.length(), -1));
        return solve(s1, s2, 0, 0);
    }
};
