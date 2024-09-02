class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) 
    {
        int ind = 0;
        long long sum = 0;
        for(auto n : chalk)
        sum += n;

        k %= sum;

        while(k > 0)
        {
            if(k < chalk[ind])
            return ind;

            else if(k == chalk[ind])
            return ind == chalk.size()-1 ? 0 : ind+1;

            k -= chalk[ind];
            ind++;

            if(ind == chalk.size())
            ind = 0;
        }

        return 0;
    }
};