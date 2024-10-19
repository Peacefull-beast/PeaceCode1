class Solution {
public:
    int nthUglyNumber(int n)
    {
        vector<int>arr(1690,0);
        int p = 0;
        int q = 0;
        int r = 0;

        int idx = 1;
        arr[0] = 1;


        while(true)
        {
            if(idx == 1690)
            break;

            int pval = arr[p]*2;
            int qval = arr[q]*3;
            int rval = arr[r]*5;

            int m = min({pval,qval,rval});

            if(pval == m) p++;
            if(rval == m) r++;
            if(qval == m) q++;

            arr[idx++] = m;
        }

        return arr[n-1];

    }
};