class Solution {
public:
    int getBit(int x, int k) 
    {
        return (x >> k) & 1;
    }
    
    
    
    vector<int> singleNumber(vector<int>& nums) 
    {
        int n = nums.size();
        int res = 0;
        
        for(int i=0; i<n; i++)
            res = res^nums[i];
        
        int pos = 0;
        while (!getBit(res, pos)) 
            pos++;
        
        
        int first = 0;
        for (int num : nums)
            if (getBit(num, pos))
                first ^= num;
        
        int sec = res^first;
        
        return {first,sec};
        
    }
};



