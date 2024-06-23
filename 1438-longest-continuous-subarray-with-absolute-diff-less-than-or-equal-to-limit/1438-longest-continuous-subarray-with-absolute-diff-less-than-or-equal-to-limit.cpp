class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int ans = 0;
        multiset<int>s;
        int i = 0; 
        int j = 0;
        
        while(j < nums.size())
        {
            s.insert(nums[j]);
            int diff = *s.rbegin() - *s.begin();
            
            while(i < j && diff > limit)
            {
                auto it = s.find(nums[i]);
                s.erase(it);
                i++;
                diff = *s.rbegin() - *s.begin();
            }
            j++;
            ans = max(ans, (int)s.size());
        }
        return ans;
    }
};