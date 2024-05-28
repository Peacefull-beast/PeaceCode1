class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) 
    {
        int n = s.length();
        int i = 0;
        int j = 0;
        int cur = 0;
        int ans = 0;
        while(j < n)
        {
            cur += abs(s[j] - t[j]);
            while(i < n && cur > maxCost)
            {
                cur -= abs(s[i] - t[i]);
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};