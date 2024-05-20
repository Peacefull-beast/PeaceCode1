class Solution {
public:
    string firstPalindrome(vector<string>& words) 
    {
        for(auto el:words)
        {
            string cpy = el;
            reverse(cpy.begin(),cpy.end());
            if(el == cpy)
                return el;
        }
        return "";
    }
};