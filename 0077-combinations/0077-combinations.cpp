class Solution {
public:
    void solve(int n ,int k, vector<int>& temp, vector<vector<int>>& ans, int i)
    {
        if(i == n+1 && temp.size() == k)
        {
            ans.push_back(temp);
            return;
        }
        
        if(i >= n+1 && temp.size() != k)
        {
            return;
        }
        
        temp.push_back(i);
        solve(n, k, temp, ans, i+1);
        temp.pop_back();
        solve(n, k, temp, ans, i+1);
        
    }
    vector<vector<int>> combine(int n, int k) 
    {
        vector<int> temp;
        vector<vector<int>> ans;
        solve(n, k, temp, ans, 1);
        return ans;        
    }
};