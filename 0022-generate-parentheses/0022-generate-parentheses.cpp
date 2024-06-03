class Solution {
public:
    void solve(int n, int open, int close, string& str, vector<string>& ans)
    {
        if (open < close)
            return;
        if (open == n && close == n)
        {
            ans.push_back(str);
            return;
        }
        
        if (open < n)
        {
            str += '(';
            solve(n, open + 1, close, str, ans);
            str.pop_back();
        }
        
        if (close < open)
        {
            str += ')';
            solve(n, open, close + 1, str, ans);
            str.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) 
    {
        string str = "";
        vector<string> ans;
        solve(n, 0, 0, str, ans);
        return ans;
    }
};
