class Solution {
public:
    int countKConstraintSubstrings(string s, int k) 
    {
        int i=0;
        int j=0;
        int z=0;
        int o=0;
        int ans = 0;
        while(j < s.size())
        {
            if(s[j] == '0')
                z++;
            else
                o++;
            
            
            while(z > k && o > k)
            {
                if(s[i] == '0')
                    z--;
                else o--;
                
                i++;   
            }
            
            ans += (j-i+1);
            j++;
        }
        
        return ans;
        
    }
};