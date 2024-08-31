class Solution {
public:
    int longestWPI(vector<int>& hours) 
    {
        unordered_map<int,int>mp;
        int score = 0;
        int ans = 0;
        for(int i=0; i<hours.size();i++)
        {
            score += (hours[i] > 8) ? 1 : -1;
            if(score > 0)
            ans = i+1;
            else
            {
                if(mp.find(score-1) != mp.end())
                ans = max(ans, i-mp[score-1]);
                if(mp.find(score) == mp.end())
                mp[score] = i;

            }
        }
        return ans;
    }
};