class Solution {
public:
    int longestPalindrome(string s) 
    {
        unordered_map<char, int> freq;
        for(auto c : s)
            freq[c]++;
        
        int odd = 0;
        int eve = 0;
        bool flag = false;
        for(auto p : freq)
        {
            int fr = p.second;
            if(fr % 2 == 0)
                eve += fr;
            else
            {
                odd += (fr - 1);
                flag = true;
            }
        }
        
        
        return odd + eve + (flag ? 1 : 0);
    }
};
