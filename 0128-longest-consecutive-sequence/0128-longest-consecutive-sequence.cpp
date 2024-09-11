class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        set<int> st(nums.begin(), nums.end());

        int ans = 1;  
        int temp = 1; 


        auto it = st.begin();
        int prev = *it; 
        ++it;  
        
        for (; it != st.end(); ++it) 
        {
            if (*it == prev + 1)
                temp++;
            else 
            {
                ans = max(ans, temp);
                temp = 1; 
            }
            prev = *it;  
        }
        
        return max(ans, temp);
    }
};
