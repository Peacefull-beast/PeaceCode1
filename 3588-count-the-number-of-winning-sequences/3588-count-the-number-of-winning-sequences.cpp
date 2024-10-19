class Solution {
public:
    map<char, int> mp;              
    int dp[1001][2001][4];          
    int mod = 1e9+7;                 


    int win(int i, int j) {
        if (i == j)
            return 0;                
        if ((i == 0 && j == 1) || (i == 1 && j == 2) || (i == 2 && j == 0))
            return -1;              
        return 1;                   
    }


    int solve(string &s, int i, int prev, int score) {
        if (i == s.size())           
            return score > 0 ? 1 : 0; 

        if (dp[i][score + 1000][1 + prev] != -1)
            return dp[i][score + 1000][1 + prev];

        int ans = 0;
        for (int j = 0; j < 3; j++) {               
            int x = mp[s[i]];                    
            if (prev != j)                       
                ans = (ans % mod + solve(s, i + 1, j, score + win(j, x)) % mod) % mod;
        }

        return dp[i][score + 1000][1 + prev] = ans;
    }


    int countWinningSequences(string s) {
        memset(dp, -1, sizeof(dp));                 
        mp['E'] = 0;                                
        mp['F'] = 1;                               
        mp['W'] = 2;                               
        return solve(s, 0, -1, 0);                 
    }
};
