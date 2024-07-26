class Solution {
public:
    long long minimumSteps(string s) 
    {
        int p1=0;
        long long ans = 0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == '0')
            {
                ans += (i-p1);
                p1++;
            }
        }
        return ans;
    }
};