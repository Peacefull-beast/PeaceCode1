class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end());
        long long happy = 0;
        int cnt = 0;
        int  i = happiness.size();
        while(k>0)
        {
            happy = happy + max(happiness[i-1]-cnt, 0);
            i-=1;
            k-=1;
            cnt+=1;
        }
        return happy;
    }
};