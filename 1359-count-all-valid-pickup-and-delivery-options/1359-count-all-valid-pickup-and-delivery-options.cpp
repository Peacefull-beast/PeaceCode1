class Solution {
public:
    int countOrders(int n) {
        long long ans = 1;
        int MOD = 1000000007;
        
        for (int i = 2; i <= n; i++) {
            ans = ans * (2 * i - 1) * i % MOD;
        }
        
        return (int)ans;
    }
};
