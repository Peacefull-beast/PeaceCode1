class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        int n = nums.size();
        
        //convert neg number to large positive
        for(int i = 0; i<n; i++)
            if(nums[i] <= 0)
                nums[i] = n+1;
        
        
        //mark visited number as neg 
        //if some nmuber present twice then it will be unmarked
        for(int i = 0; i<n; i++)
        {
            if(abs(nums[i]) <= n && nums[abs(nums[i]) - 1] > 0)
                nums[abs(nums[i]) - 1] *= -1;
            
        }
        
        
        // if something found postive that index is not visitd
        for(int i = 0; i<n; i++)
        {
            if(nums[i] > 0)
                return i+1;
        }
        
        // else return n+1 all numbers till n present
        return n+1;
        
        

    }
};