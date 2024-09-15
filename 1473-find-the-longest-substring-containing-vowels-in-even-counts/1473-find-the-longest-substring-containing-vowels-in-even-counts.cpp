class Solution {
public:
    string bflip(char ch, string &str)
    {
        if(ch == 'a')
            str[0] = str[0] == '0' ? '1' : '0';  
        else if(ch == 'e')
            str[1] = str[1] == '0' ? '1' : '0';

        else if(ch == 'i')
            str[2] = str[2] == '0' ? '1' : '0';

        else if(ch == 'o')
            str[3] = str[3] == '0' ? '1' : '0';

        else if(ch == 'u')
            str[4] = str[4] == '0' ? '1' : '0';

        return str;
    }

    int findTheLongestSubstring(string s) 
    {
        unordered_map<string, int> mp;

        int ans = 0;
        string str = "00000"; 
        mp[str] = -1;  
        for(int i = 0; i < s.size(); i++)
        {
            str = bflip(s[i], str);  
            if(mp.find(str) == mp.end())
                mp[str] = i;  
            else
                ans = max(ans, i - mp[str]); 
        }

        return ans;
    }
};
