class Solution {
public:
    void solve(int n, int cnt, int prev, vector<string>& res, string str)
    {
        if(cnt == n)
        {
            res.push_back(str);
            return;
        }
        if(prev == 0)
        {
            str += "1";
            solve(n, cnt+1, 1, res, str);
        }
        else
        {
            str += "0";
            solve(n, cnt+1, 0, res, str);
            str.pop_back();
            str += "1";
            solve(n, cnt+1, 1, res, str);
        }
        
        
    }
    vector<string> validStrings(int n) 
    {
        vector<string>res;
        solve(n, 0, 1, res, "");
        return res;
    }
};