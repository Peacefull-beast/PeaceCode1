class Solution {
public:
    int numberOfSpecialChars(string word) 
    {
        unordered_map<char,char>mp;
        
        vector<int>uc(26, 0);
        vector<int>lc(26, 0);
        
        for(auto ch : word)
        {
            if(ch >= 'a' && ch <= 'z')
            {
                if(uc[ch - 'a'] == 1 ||  uc[ch - 'a'] == 3)
                   uc[ch - 'a'] = 3;
                else
                    lc[ch - 'a'] = 1;
            }
            else if(ch >= 'A' && ch <= 'Z')
                if(uc[ch - 'A'] != 3)
                    uc[ch - 'A'] = 1;
        }
        
        int ans = 0;
        for(int i = 0; i < 26 ;i++)
        {
            if(lc[i] == 1 & uc[i] == 1)
                ans++;
        }
        
        return ans;
        
    }
};