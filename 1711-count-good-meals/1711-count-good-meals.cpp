class Solution {
public:
    int countPairs(vector<int>&nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        vector<int>powers;
        for(int i=0;i<=21;i++){
            powers.push_back(pow(2,i));
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int pow=0;pow<powers.size();pow++)
            {
                if(mp.find(powers[pow]-nums[i])!=mp.end()){
                    ans=(ans+mp[powers[pow]-nums[i]])%1000000007;
                }
            }
            mp[nums[i]]++;
        }
        return (ans)%1000000007;
    }
};