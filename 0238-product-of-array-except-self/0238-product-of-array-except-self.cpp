class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int num_zeros = 0;
        int pro = 1;
        vector<int>left;
        vector<int>right;
        for(auto el:nums)
        {
            pro *= el;
            left.push_back(pro);
        }
        
        
        pro = 1;
        reverse(nums.begin(), nums.end());
        
        
        for(auto el:nums)
        {
            pro *= el;
            right.push_back(pro);
        }
        
        reverse(right.begin(), right.end());
        vector<int> ans;
        ans.push_back(right[1]);
        
        for(int i = 1; i<nums.size()-1; i++)
            ans.push_back(left[i-1]*right[i+1]);
        
        ans.push_back(left[nums.size()-2]);
        return ans;

    }
        
};