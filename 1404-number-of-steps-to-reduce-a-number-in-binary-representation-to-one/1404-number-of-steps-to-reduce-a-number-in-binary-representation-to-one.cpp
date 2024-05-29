class Solution {
public:
    int numSteps(string s) 
    {
        int ans = 0;
        
        while (s != "1")
        {
            int n = s.length();
        
            if (s[n-1] == '0')
                s = s.substr(0, n-1); 
            else
            {
                int i = n - 1;
                while (i >= 0 && s[i] == '1')
                {
                    s[i] = '0';
                    i--;
                }
                if (i >= 0)
                    s[i] = '1';
                else 
                    s = '1' + s;
            }
            
            ans++;
        }
        
        return ans;
    }
};
