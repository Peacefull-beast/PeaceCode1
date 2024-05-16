class Solution {
public:
    int pivotInteger(int n) 
    {
         if(n ==1)
             return 1;
        vector<int> preSum;
        int sum = 0;
        for(int i = 1; i <= n; i++)
        {
            sum+=i;
            preSum.push_back(sum);
        }
        for(int i = n-2; i>0; i--)
        {
            if(preSum[i-1] == (preSum[n-1]-preSum[i]))
               return i+1;
        }
               return -1;
    }
};