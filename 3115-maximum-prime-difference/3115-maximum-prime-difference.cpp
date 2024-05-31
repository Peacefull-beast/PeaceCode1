class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) 
    {
        int first = 0;
        int last = 0;
        int n = 101;
        vector<bool> is_prime(n, true);
        is_prime[0] = is_prime[1] = false;
        for (int p = 2; p * p <= n; ++p) 
        {
            if (is_prime[p]) 
            {
                for (int i = p * p; i < n; i += p)
                is_prime[i] = false;
            }
        }
        for(int i=0; i<nums.size();i++)
        {
            if(is_prime[nums[i]] == true && first == 0)
                first = i + 1;
            if(is_prime[nums[i]] == true && first != 0)
                last = i + 1;
        }
        
        return last-first;
    }
};