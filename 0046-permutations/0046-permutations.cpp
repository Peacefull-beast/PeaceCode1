class Solution {
public:
    void func(vector<vector<int>> &ans,vector<int>& nums, int ind)
    {
        if(ind==nums.size())
        {
            vector<int>ds;
            for(int i=0;i<nums.size();i++)
                ds.push_back(nums[i]);
            ans.push_back(ds);     
        }
        for(int i=ind;i<nums.size();i++)
        {
            swap(nums[i],nums[ind]);
            func(ans,nums,ind+1);
            swap(nums[i],nums[ind]);
        }
    }
            
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>>ans;
        func(ans,nums,0);
        return ans;
            
    }
};