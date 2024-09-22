class Solution {
public:
    vector<int>ans;
    void solve(int curr, int n)
    {
        if(curr > n)
            return;

        ans.push_back(curr);
        
        for(int t = 0; t <= 9; t++)
        {
            int nnum = curr * 10 + t;
            if(nnum > n)
                return;

            else
                solve(nnum, n);
        }
        return;
    }
    vector<int> lexicalOrder(int n) 
    {
        for(int curr = 1; curr <= 9; curr ++)
            solve(curr, n);

        return ans;
    }
};