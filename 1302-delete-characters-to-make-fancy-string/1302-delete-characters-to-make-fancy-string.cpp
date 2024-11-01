class Solution {
public:
    string makeFancyString(string s) 
    {
        string str = "";
        int i = 0;
        int j = 0;

        while(j < s.size())
        {
            i = j;
            while(s[i] == s[j] && i < s.size())
                i++;

            for(int t = 0; t < min(i-j, 2); t++)
                str += s[j];

            j = i;
        }
        return str;

    }
};