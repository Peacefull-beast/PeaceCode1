class Solution {
public:
    void solve(vector<int>& cand, int tar, vector<int>& temp, vector<vector<int>>& ans, int ind)
    {
        if(tar == 0)
        {
            ans.push_back(temp);
            return;
        }
        if(tar < 0 || ind >= cand.size())
            return;
        
        for(int i = ind; i < cand.size(); i++)
        {
            if(i > ind && cand[i] == cand[i-1]) continue;
            
            temp.push_back(cand[i]);
            solve(cand, tar - cand[i], temp, ans, i + 1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        vector<vector<int>> ans;
        solve(candidates, target, temp, ans, 0);
        return ans;
    }
};
