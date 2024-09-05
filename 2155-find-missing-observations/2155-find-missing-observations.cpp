class Solution {
public:
    vector<int> constructArray(int n, int s) 
    {
        if (s < n || s > 6 * n) 
        return {}; 

    
        vector<int> result(n, 1);
        int currentSum = n;

    
        int i = 0;
        while (currentSum < s) 
        {
            int increase = min(6 - result[i], s - currentSum); 
            result[i] += increase;
            currentSum += increase;
            i = (i + 1) % n;
        }

        return result;
    }
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) 
    {
        int sum = 0;
        int m = rolls.size();
        for(auto num : rolls)
            sum += num;

        int nx = mean*(n+m) - sum;


        if(nx > 6*n)
        return {};

        else
        return constructArray(n, nx);
    }
};