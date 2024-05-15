class Solution {
public:
    string maximumOddBinaryNumber(string s) 
    {
        int n1 = 0;
        int n0 = 0;
        for(int i = 0; i<s.length();i++)
        {
            if(s[i] == '1')
                n1+=1;
            else
                n0+=1;
        }
        
        string ans = "1";
        n1-=1;
        
        string s0 = "";
        string s1 = "";
        for(int i = 1; i<=n0; i++)
            s0+='0';
        
        for(int i = 1; i<=n1; i++)
            s1+='1';
        
        ans = s1+s0+ans;
        return ans;
    }
    
    
};