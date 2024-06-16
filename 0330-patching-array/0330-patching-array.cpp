class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long int mpatch = 0;
        long int mn = 0, i = 0, sz = nums.size();
        while(mn < n)
        {
            if(i < sz && mn+1 >= nums[i])
            {
                mn += nums[i];
                i++;
            }
            else
            {
                mpatch++;
                mn += (mn+1);
            }
        }
        return mpatch;
    }
};