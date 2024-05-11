class Solution {
public:
    int findMaxK(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = nums.size()-1;
        if(nums[i]>0)
        return -1;
        while(i<=j)
        {
            if(i == j)
                break;
            if(abs(nums[i]) == nums[j] && nums[i] + nums[j] == 0)
                return nums[j];
            else if( abs(nums[i]) < nums[j])
                j--;
            else if( abs(nums[i]) > nums[j])
                i++;
        }
        return -1;
    }
};