class Solution {
public:
    bool ans (string s, string t)
    {
        unordered_map<char,char>mp;
        for(int i = 0; i<s.length();i++)
        {
            char chs = s[i];
            char cht = t[i];
            
            auto it = mp.find(chs);
            if (it != mp.end())
            {
                if(mp[chs] != cht)
                    return false;
            }
            else
                mp[chs] = cht;
        }
        return true;
    }
    bool isIsomorphic(string s, string t) 
    {
        bool a1 = ans(s,t);
        bool a2 = ans(t,s);
        if(a1 && a2)
            return true;
        else
            return false;
    }
};