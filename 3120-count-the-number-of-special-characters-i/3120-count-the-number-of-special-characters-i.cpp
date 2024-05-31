class Solution {
public:
    int numberOfSpecialChars(string word) 
    {
        unordered_map<char,char>mp;
        
        vector<bool>uc(26, false);
        vector<bool>lc(26, false);
        
        for(auto ch : word)
        {
            if(ch >= 'a' && ch <= 'z')
                lc[ch - 'a'] = true;
            else
                uc[ch - 'A'] = true;
        }
        
        int ans = 0;
        for(int i = 0; i < 26 ;i++)
        {
            if(lc[i] & uc[i])
                ans++;
        }
        
        return ans;
    }
};