class Solution {
public:
    vector<string> fun(string s)
    {
        vector<string> ans;
        int i = 0;
        
        for (int ind = 0; ind <= s.size(); ind++)  // Change condition to `<=` to handle the last word
        {
            if (ind == s.size() || s[ind] == ' ')  // Check for space or end of string
            {
                ans.push_back(s.substr(i, ind - i));  // Push the current word
                i = ind + 1;  // Move the start index to the next word
            }
        }
        return ans;
    }

    bool wordPattern(string pattern, string s) 
    {
        vector<string> str = fun(s);
        if (pattern.size() != str.size())  
            return false;

        unordered_map<char, string> mp;
        unordered_map<string, char> mp_rev;  
        
        for (int i = 0; i < pattern.size(); i++)
        {
            char c = pattern[i];
            string word = str[i];
            
            
            if (mp.find(c) == mp.end())
            {
                
                if (mp_rev.find(word) != mp_rev.end())
                    return false;
                
                mp[c] = word;
                mp_rev[word] = c;
            }
            else
            {
                
                if (mp[c] != word)
                    return false;
            }
        }
        
        return true;
    }
};
