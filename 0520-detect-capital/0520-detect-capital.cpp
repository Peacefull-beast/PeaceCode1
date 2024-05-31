class Solution {
public:
    bool detectCapitalUse(string word) 
    {
        if(word[0] >= 'A' && word[0] <= 'Z')
            word = word.substr(1);
        bool cap = false;
        bool sma = false;
        for(auto ch : word)
        {
            if(ch >= 'a' && ch <= 'z')
                sma = true;
            else
                cap = true;
        }
        if(word == "" || word.length() == 1)
            return true;
        else return (sma^cap);
    }
    
    
};