class Solution {
public:
    bool reportSpam(vector<string>& bannedWords, vector<string>& message) 
    {
        unordered_set<string>st(message.begin(), message.end());

        int t = 0;
        for(auto w : bannedWords)
        {
            if(st.find(w) != st.end())
                t++;

            if(t >= 2)
            return true;
        }
        return false;
    }
};