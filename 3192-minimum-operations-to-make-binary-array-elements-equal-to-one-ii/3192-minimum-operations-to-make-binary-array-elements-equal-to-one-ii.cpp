class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        int flips = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i] == 0 && flips%2 == 0)
                flips++;
            
            else if(nums[i] == 1 && flips%2 == 1)
                flips++;
        }
        
        return flips;
    }
};




