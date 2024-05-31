class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) 
    {
        vector<int>ans;
        ans.push_back(first);
        int p = first;
        for(auto num: encoded)
        {
            ans.push_back(num^p);
            p = num^p;
        }
        
        return ans;
    }
};