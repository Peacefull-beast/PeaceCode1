class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int i = 0;
        int j = 0;
        
        int ans = 0;
        unordered_map<char, int> freq;
        int len = 0;
        
        while (j < s.length()) 
        {
            freq[s[j]]++;
            while (freq[s[j]] > 1) 
            {
                freq[s[i]]--;
                i++;
                len--;
            }
            j++;
            len++;
            ans = max(ans, len);
        }
        return ans;
    }
};
