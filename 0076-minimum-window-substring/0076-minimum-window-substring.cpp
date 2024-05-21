class Solution {
public:
    string minWindow(string s, string t) 
    {
        if(s.length() < t.length())
            return "";

        unordered_map<char, int> tmp;
        for (auto ch : t) tmp[ch]++;
        
        int j = 0;
        int i = 0;
        int cnt = t.length();  // Total characters we need to match
        int start = 0;
        int len = INT_MAX;
        
        int n = s.size();
        
        while (j < n) 
        {
            // Process the current character
            if (tmp[s[j]] > 0) cnt--;  // Found a needed character
            tmp[s[j]]--;
            j++;
            
            // When we have all characters matched
            while (cnt == 0) 
            {
                // Update minimum window
                if (j - i < len) 
                {
                    start = i;
                    len = j - i;
                }
                
                // Slide the window
                tmp[s[i]]++;
                if (tmp[s[i]] > 0) cnt++;  // When the current character is part of t
                i++;
            }
        }
        
        return (len != INT_MAX ? s.substr(start, len) : "");
    }
};
