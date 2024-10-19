class Solution {
public:
    map<char, int> mp;               // Mapping characters to integers
    int dp[1001][2001][4];           // DP array with size limits for string length, score, and previous moves
    int mod = 1e9+7;                 // Modulo value to avoid overflow

    // Function to determine the result of the game based on moves (Rock, Paper, Scissors-like game logic)
    int win(int i, int j) {
        if (i == j)
            return 0;                // Tie condition
        if ((i == 0 && j == 1) || (i == 1 && j == 2) || (i == 2 && j == 0))
            return -1;               // Losing condition
        return 1;                    // Winning condition
    }

    // Recursive function to solve the problem using dynamic programming
    int solve(string &s, int i, int prev, int score) {
        if (i == s.size())           // If we've processed the entire string
            return score > 0 ? 1 : 0; // Return 1 if the score is positive, otherwise return 0

        if (dp[i][score + 1000][1 + prev] != -1)   // Memoization check
            return dp[i][score + 1000][1 + prev];

        int ans = 0;
        for (int j = 0; j < 3; j++) {               // Loop through the three possible moves
            int x = mp[s[i]];                       // Get the mapped value of the current character
            if (prev != j)                          // Check that the previous move isn't the same as the current move
                ans = (ans % mod + solve(s, i + 1, j, score + win(j, x)) % mod) % mod;
        }

        return dp[i][score + 1000][1 + prev] = ans; // Store result in the DP table
    }

    // Function to count winning sequences
    int countWinningSequences(string s) {
        memset(dp, -1, sizeof(dp));                 // Initialize DP array to -1 (unvisited)
        mp['E'] = 0;                                // Map 'E' to 0
        mp['F'] = 1;                                // Map 'F' to 1
        mp['W'] = 2;                                // Map 'W' to 2
        return solve(s, 0, -1, 0);                  // Start solving from the beginning with no previous move and score 0
    }
};
