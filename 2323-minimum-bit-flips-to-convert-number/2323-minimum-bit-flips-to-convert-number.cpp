class Solution {
public:
    int minBitFlips(int start, int goal) 
    {
        int m1 = max(start,goal);
        int m2 = min(start,goal);
        int ans = 0;
        while(m1 != 0)
        {
            int p1 = m1 & 1;
            int p2 = m2 & 1;

            if(p1 != p2)
            ans++;

            m1 = m1 >> 1;
            m2 = m2 >> 1;

        }
        return ans;
    }
};