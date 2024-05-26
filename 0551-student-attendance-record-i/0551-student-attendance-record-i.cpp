class Solution {
public:
    bool checkRecord(string s) 
    {
        int lc = 0;
        int ac = 0;
        
        for(int i = 0; i < s.length(); i++) 
        {
            if(s[i] == 'A')
                ac += 1;
            
            if(s[i] == 'L')
            {
                lc += 1;
                if (lc >= 3) // Check if there are 3 consecutive 'L's
                    return false;
            } 
            else 
                lc = 0;
            
            if(ac >= 2)
                return false;
        }
        return true;
    }
};
