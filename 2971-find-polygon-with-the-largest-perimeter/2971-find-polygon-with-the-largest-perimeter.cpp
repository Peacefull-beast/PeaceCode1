#define ll long long
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        ll sum = 0;
        for(auto side: nums)
            sum += side;
        int i = nums.size()-1;
        while(i >= 2)
        {
            sum = sum - nums[i];
            if(sum > nums[i])
                return sum+nums[i];
            i--;
        }
        
        return -1;
    }
};