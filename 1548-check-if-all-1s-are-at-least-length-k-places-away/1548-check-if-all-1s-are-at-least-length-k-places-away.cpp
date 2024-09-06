class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) 
    {
        int i = 0;
        
        int  n = nums.size();
        while(i < n)
        {
            if(nums[i] == 1)
                break;
            i++;
        }

        int j = i+1;
        while(j < n)
        {
            if(nums[j] == 1)
            {
                //cout<<i << j<<endl;
                if(j - i - 1 < k)
                return false;
                i = j;
            }
            j++;
        }
             
         
        return true;
    }
};