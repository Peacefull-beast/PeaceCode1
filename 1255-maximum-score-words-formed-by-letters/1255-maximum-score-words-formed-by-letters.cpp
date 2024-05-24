class Solution {
public:
    bool eligible(string &str, unordered_map<char, int> mp) {
        for (auto ch : str) {
            if (mp[ch] <= 0) {
                return false;
            }
            mp[ch]--;
        }
        return true;
    }

    int solve(vector<string>& words, unordered_map<char, int> mp, vector<int>& score, int ind) 
    {
        if (ind == words.size())
            return 0;
        
        int pck = 0;
        int npck = solve(words, mp, score, ind + 1);;
        
        if (eligible(words[ind], mp)) 
        {
            int temp = 0;
            string word = words[ind];
            for (auto ch : word) 
            {
                temp += score[ch - 'a'];
                mp[ch]--;
            }
            pck = temp + solve(words, mp, score, ind + 1);
        }
        
        
        return max(pck, npck);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) 
    {
        unordered_map<char, int> mp;
        for (auto ch : letters)
            mp[ch]++;
        
        return solve(words, mp, score, 0);
    }
};