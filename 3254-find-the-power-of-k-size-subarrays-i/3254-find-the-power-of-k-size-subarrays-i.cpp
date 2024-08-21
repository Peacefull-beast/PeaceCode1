class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) 
    {
        vector<int> vec;
        
        for(int i = 0; i <= nums.size() - k; i++) 
        {
            bool f = true;
            for(int j = i; j < i + k - 1; j++) 
            {
                if(nums[j]+1 != nums[j + 1])
                {
                    f = false;
                    break;
                }
            }
            if(f) 
                vec.push_back(nums[i + k - 1]);
            else vec.push_back(-1);
        }
        return vec;
        
        
    }
};