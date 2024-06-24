class Solution {
public:
    bool isAnagram(string s, string x) 
    {
        vector<int>t(26,0);
        for(auto c:s)
            t[c-'a']++;
        
        for(auto c:x)
        {
            if(t[c-'a']==0)
                return false;
            t[c-'a']--;
        }
        
        for(int i=0;i<26;i++)
            if(t[i] != 0)
                return false;
        
        return true;
    }
};