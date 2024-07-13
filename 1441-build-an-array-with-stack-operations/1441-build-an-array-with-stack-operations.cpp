class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) 
    {
        vector<string> ans;
        int cnt = 1;

        for (int num : target)
        {
            while (cnt < num)
            {
                ans.push_back("Push");
                ans.push_back("Pop");
                cnt++;
            }
            ans.push_back("Push");
            cnt++;
        }

        return ans;
    }
};
