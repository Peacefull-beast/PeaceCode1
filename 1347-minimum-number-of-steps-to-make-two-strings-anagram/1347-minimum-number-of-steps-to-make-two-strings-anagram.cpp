class Solution {
public:
    int minSteps(string s, string t) 
    {
        unordered_map<char,int>freq;
        for(int  i = 0; i< s.length(); i++)
        {
            freq[s[i]]++;
            freq[t[i]]--;
        }
        
        int ans = 0;
        for(auto p:freq)
        {
            if(p.second > 0)
                ans+=p.second;
        }
        
        return ans;
    }
};