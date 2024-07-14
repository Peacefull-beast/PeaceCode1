class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        
        unordered_set<char>letters;
        for(auto c : s)
            letters.insert(c);
        
        
        int res = 0;
        
        
        for(auto c : letters)
        {
            int l_ind = -1;
            int r_ind = -1;
            
            for(int i=0; i<n; i++)
            {
                if(s[i] == c)
                {
                    if(l_ind == -1)
                        l_ind = i;
                    r_ind = i;
                }
                
            }
            unordered_set<char>uni;
            for(int i=l_ind+1; i<=r_ind-1; i++)
                uni.insert(s[i]);
            
            res += uni.size();
        }
        
        
        return res;
    }
};