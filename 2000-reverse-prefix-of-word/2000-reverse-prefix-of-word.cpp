class Solution {
public:
    string reversePrefix(string word, char ch) 
    {
        int i=0;
        string str;
        bool flag = false;
        for(i=0; i<word.length();i++)
        {
            str = str + word[i];
            if(word[i] == ch)
            {
                flag = true;
                break;
            }
        }
        if(flag == false)
            return word;

        reverse(str.begin(),str.end());
        string ans = str+ word.substr(i+1);
        return ans;
    }
};