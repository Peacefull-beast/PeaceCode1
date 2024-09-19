class Solution {
public:
    vector<int> diffWaysToCompute(string s) 
    {
        vector<int>ans;
        for(int i=0; i<s.length(); i++)
        {
            if(isdigit(s[i]) == false)
            {
                vector<int>l_res = diffWaysToCompute(s.substr(0,i));
                vector<int>r_res = diffWaysToCompute(s.substr(i+1));

                for(auto x : l_res)
                {
                    for(auto y : r_res)
                    {
                        if(s[i] == '*')
                            ans.push_back(x*y);
                        if(s[i] == '+')
                            ans.push_back(x+y);
                        if(s[i] == '-')
                            ans.push_back(x-y);
                    }
                }
            }
        }
        if(ans.empty())
        ans.push_back(stoi(s));
        return ans;
    }
};