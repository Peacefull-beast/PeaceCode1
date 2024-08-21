class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) 
    {
        vector<int>ans;
        int c = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(i && nums[i] == nums[i-1]+1)
                c++;
            else
                c=1;
            if(i+1 >= k)
                ans.push_back(c >= k ? nums[i] : -1);
        }
        return ans;
    }
};