class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int i = 0;
        int j = 0;
        
        int maxl = 0;
        int maxf = 0;
        vector<int>map(26, 0);
        
        while (j < s.length())
        {
            map[s[j] - 'A']++;
            maxf = max(maxf, map[s[j] - 'A']);
            int len = j - i + 1;
            
            if (len - maxf > k)
            {
                map[s[i] - 'A']--;
                i++;
            }
            
            maxl = max(maxl, j - i + 1);
            j++;
        }
        
        return maxl;
    }
};
