class Solution {
public:
    int longestSubarray(vector<int>& nums) 
    {

        int x = *max_element(nums.begin(), nums.end());

        int maxl = 0;  
        int l = 0;     
        

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == x)  
                l++;          
            else
            {
                maxl = max(maxl, l);  
                l = 0;               
            }
        }
        
        
        maxl = max(maxl, l);

        return maxl;
    }
};
