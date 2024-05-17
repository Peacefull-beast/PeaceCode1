class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int, int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        int ans = 0;
        for(auto it:mp)
        {
            while(it.second != 0){
                if(it.second % 3 == 2)
                {
                    ans++;
                    it.second-=2;
                }  
                else if(it.second % 3 == 1)
                {
                    cout<<"in";
                    if(it.second == 1)
                        return -1;
                    ans+=2;
                    it.second-=4;
                    // cout<<it.second;
                }
                else
                {
                    ans+=(it.second/3);
                    cout<<ans;
                    it.second = 0;
                }
            }
        }
        return ans;
    }
};