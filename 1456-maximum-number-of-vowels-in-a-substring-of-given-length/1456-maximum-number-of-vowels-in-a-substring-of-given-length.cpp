class Solution {
public:
    bool isvow(char c)
    {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        return false;
    }
    int maxVowels(string s, int k) 
    {
        int ans = 0;
        int temp = 0;
        
        for(int i = 0; i<k; i++)
            if(isvow(s[i]))
                temp++;
        
        ans = temp;
        
        for(int i = k; i<s.length(); i++)
        {
            if(!isvow(s[i-k]) && isvow(s[i]))
                temp+=1;
            else if(isvow(s[i-k]) && isvow(s[i]) || !isvow(s[i-k]) && !isvow(s[i]))
                temp+=0;
            else
                temp-=1;
            ans = max(ans, temp);
        }
        
        
        return ans;
    }
};