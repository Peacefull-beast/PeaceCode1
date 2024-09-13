class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) 
    {
        int n = arr.size();
        vector<int> pre(n, 0);

        
        pre[0] = arr[0];
        for(int i = 1; i < n; i++)
        {
            pre[i] = pre[i-1] ^ arr[i];
        }

        vector<int> ans;
        for(auto& q : queries)
        {
            int u = q[0];
            int v = q[1];

            
            int answer = (u == 0) ? pre[v] : pre[v] ^ pre[u-1];
            ans.push_back(answer);
        }

        return ans;
    }
};
