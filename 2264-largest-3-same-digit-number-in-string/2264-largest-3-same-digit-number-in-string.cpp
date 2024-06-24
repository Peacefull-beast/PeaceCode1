class Solution {
public:
    string largestGoodInteger(string s) 
    {
        string ans = "";
        int maxi = 0;
        for(int i=0; i<s.length()-2; i++)
        {
            if(s[i] == s[i+1] && s[i+1] == s[i+2])
            {
                if(s[i]-'0' >= maxi)
                {
                    ans = s.substr(i,3);
                    maxi = s[i]-'0';
                }
            }
        }
        
        return ans;
    }
};