class Solution {
public:
    void solve(vector<int>& cand, int tar, vector<int>& temp, vector<vector<int>>& ans, int ind)
    {
        if(tar < 0)
            return;
        if(ind == cand.size() && tar == 0)
        {
            ans.push_back(temp);
            return;
        }
        if(ind == cand.size() && tar != 0)
            return;
        
        temp.push_back(cand[ind]);
        solve(cand, tar-cand[ind], temp, ans, ind);
        temp.pop_back();
        solve(cand, tar, temp, ans, ind+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<int> temp;
        vector<vector<int>> ans;
        solve(candidates, target, temp, ans, 0);
        return ans;
    }
};