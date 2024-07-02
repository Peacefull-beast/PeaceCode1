class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int res = 0;
        for(int bit=0; bit<=31;bit++)
        {
            int cnt0=0;
            int cnt1=0;
            int temp = (1<<bit);
            for(auto num:nums)
            {
                if((num&temp) == 0)
                    cnt0++;
                else
                    cnt1++;
            }
            
            if(cnt1%3 == 1)
                res = res|temp;
        }
        return res;
    }
};