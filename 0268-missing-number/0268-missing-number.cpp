class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int n = nums.size();
        int psum = (n * (n+1))/2;
        int csum = 0;
        for(auto num:nums)
            csum+=num;
        
        return psum-csum;
    }
};