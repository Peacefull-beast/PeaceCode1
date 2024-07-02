class Solution {
public:
    int M = 1e9 + 7;

    int maximumXorProduct(long long a, long long b, int n) {
        long long xa = 0;
        long long xb = 0;

        for (int i = 49; i >= n; i--) {
            bool ibita = ((a >> i) & 1) > 0;
            bool ibitb = ((b >> i) & 1) > 0;
            
            if (ibita)
                xa = xa ^ (1LL << i);
            if (ibitb)
                xb = xb ^ (1LL << i);
        }

        for (int i = n - 1; i >= 0; i--) {
            bool ibita = ((a >> i) & 1) > 0;
            bool ibitb = ((b >> i) & 1) > 0;

            if (ibita == ibitb) {
                xa = xa ^ (1LL << i);
                xb = xb ^ (1LL << i);
            } else {
                if (xa > xb)
                    xb = xb ^ (1LL << i);
                else
                    xa = xa ^ (1LL << i);
            }
        }

        xa %= M;
        xb %= M;

        return (xa * xb) % M;
    }
};
