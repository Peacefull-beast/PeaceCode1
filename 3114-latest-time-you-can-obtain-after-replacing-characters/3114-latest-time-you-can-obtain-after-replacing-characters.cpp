class Solution {
public:
    string findLatestTime(string s) 
    {
        // Handle hours
        if (s[0] == '?' && s[1] == '?')  // "??"
        {
            s[0] = '1';
            s[1] = '1';
        } 
        else if (s[0] == '?') // "?x"
        {
            if (s[1] == '0' || s[1] == '1') 
                s[0] = '1';
            else 
                s[0] = '0';
        } 
        else if (s[1] == '?') // "x?"
        { 
            if (s[0] == '1') 
                s[1] = '1';
            else if (s[0] == '0')
                s[1] = '9';
            else
                s[1] = '9';
        }

        // Handle minutes
        if (s[3] == '?' && s[4] == '?') // "??"
        { 
            s[3] = '5';
            s[4] = '9';
        } 
        else if (s[3] == '?') // "?x"
            s[3] = '5';
        else if (s[4] == '?')  // "x?"
            s[4] = '9';

        return s;
    }
};
