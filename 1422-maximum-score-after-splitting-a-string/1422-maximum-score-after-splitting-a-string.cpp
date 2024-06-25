class Solution {
public:
    int maxScore(string s) 
    {
        int n1=0;
        for(auto c:s)
        {
            if(c=='1')
                n1++;
        }
        
        int n0_inleft = 0;
        int score = 0;
        
        for(int i=1;i<s.length();i++)
        {
            if(s[i-1] == '0')
                n0_inleft++;
            if(s[i-1] == '1')
                n1--;
            score = max(score,(n0_inleft+n1));
        }
        
        return score;
    }
};