class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        int n = s.length();
        int ans = 0;
        bool flag = false;
        for(int i = n-1; i>=0; i--)
        {
            if(s[i] != ' ')
            {
                flag = true;
                ans++;
            }
            else if(s[i] == ' ' && flag == false)
                continue;
            else if(s[i] == ' ' && flag == true)
                break;

        }
        return ans;
    }
};