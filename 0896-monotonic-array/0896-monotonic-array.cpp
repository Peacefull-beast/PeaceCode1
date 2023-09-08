class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool flag1=true;
        bool flag2=true;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<nums[i-1])
            {
                flag1=false;
                break;
            }
        }
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
            {
                flag2=false;
                break;
            }
        }
        
        if(flag1 == false && flag2 == false)
            return false;
        return true;
        
    }
};