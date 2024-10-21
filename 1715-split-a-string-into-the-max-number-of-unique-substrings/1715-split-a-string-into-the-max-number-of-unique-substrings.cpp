class Solution {
public:
    int fun(int ind, string &s, unordered_set<string>&seen)
    {
        if(ind == s.size())
        return 0;

        int maxsplits = 0;
        for(int i = ind+1; i <= s.size(); i++)
        {
            string str = s.substr(ind, i-ind);
            if(seen.find(str) == seen.end())
            {
                seen.insert(str);
                maxsplits = max(maxsplits, 1 + fun(i, s, seen));
                seen.erase(str);
            }
        }
        return maxsplits;
    }
    int maxUniqueSplit(string s) 
    {
        unordered_set<string>seen;
        return fun(0,s,seen);
    }
};