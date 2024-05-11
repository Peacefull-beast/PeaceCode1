class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int,int>>rank;
        for(int i = 0; i<score.size();i++)
        {
            rank.push_back({score[i],i+1});
        }
        sort(rank.begin(),rank.end());
        reverse(rank.begin(),rank.end());
        vector<string>ans(score.size(),"");
        for(int i=0; i<rank.size(); i++)
        {
            string plc = "";
            if(i+1 == 1)
                plc = "Gold Medal";
            else if(i+1 == 2)
                plc = "Silver Medal";
            else if(i+1 == 3)
                plc = "Bronze Medal";
            else
                plc = to_string(i+1);
            
            int ind = rank[i].second;
            ans[ind-1] = plc;
            
        }
        return ans;
        
        
    }
};

           