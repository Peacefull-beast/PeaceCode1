class Solution {
public:
    void recur(string &digits, int ind, vector<string>& map, string &str, vector<string>& ans)
    {
        if (ind == digits.length())
        {
            if (str != "")
                ans.push_back(str);   
            return;
        }
        
        int digit = digits[ind] - '0';
        for (int i = 0; i < map[digit].length(); i++)
        {
            str += map[digit][i];
            recur(digits, ind + 1, map, str, ans);
            str.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) 
    {
        if (digits.empty())
            return {};
        
        vector<string> map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string str = "";
        recur(digits, 0, map, str, ans);
        return ans;
    }
};
