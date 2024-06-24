class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        int ans = 0;
        int t=0;
        vector<int>flipped(n, 0);
        
        for(int i=0; i<n; i++)
        {
            if(i>=k)
                t-=flipped[i-k];
            
            if((nums[i]==1 && t%2==1) || nums[i]==0 && t%2==0)
            {
                if(i+k > n)
                    return -1;
            ans++;
            t++;
            flipped[i] = 1;
            }
        }
        return ans;
    }
};