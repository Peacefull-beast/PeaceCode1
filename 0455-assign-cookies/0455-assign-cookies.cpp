class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int m = g.size();
        int n = s.size();
        int i = m-1; 
        int j = n-1;
        int ans = 0;
        while(i >= 0 && j >=0)
        {
            if(g[i] <= s[j])
            {
                cout<<i<<j<<" ";
                ans++;
                i--;
                j--;
            }
            else
            {
                i--;
            }
            if( i<0 || j<0)
                break;
        }
        return ans;
    }
    
};