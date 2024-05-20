
#define ll long long
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) 
    {
        int maxn = INT_MIN;
        for(int i = 0; i<nums.size();i++)
            maxn = max(maxn, nums[i]);
        
        
        long long ans = 0;
        cout<<maxn;
        int i = 0; int j = 0;
        int temp = 0;
        while(j < nums.size())
        {
            if(nums[j] == maxn)
                temp++;
            while(temp >= k )
            {
                ans+=(nums.size() - j);
                if(nums[i] == maxn)
                    temp--;
                i++;
            } 
            j++;
                
        }
        return ans;
    }
};