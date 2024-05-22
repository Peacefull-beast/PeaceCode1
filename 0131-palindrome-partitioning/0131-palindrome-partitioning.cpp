class Solution {
public:
    bool check(string &s, int start, int end)
    {
        while(start <= end)
        {
            if(s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

    void fun(string &s, vector<vector<string>> &ans, vector<string>& temp, int ind)
    {
        if(ind == s.length())
        {
            ans.push_back(temp);
            return;
        }
        for(int i = ind; i < s.length(); i++)
        {
            if(check(s, ind, i))
            {
                temp.push_back(s.substr(ind, i - ind + 1));
                fun(s, ans, temp, i + 1);
                temp.pop_back();
            }    
        }
    }

    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> ans;
        vector<string> temp;
        fun(s, ans, temp, 0);
        return ans;
    }
};
