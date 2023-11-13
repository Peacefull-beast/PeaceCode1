#define MOD 1000000007

class Solution {
public:
    int countGoodNumbers(long long n) {
        long long ans = 1;

        long long even, odd;
        
        // Calculate even and odd counts
        if (n % 2 != 0) {
            even = n / 2 + 1;
            odd = n / 2;
        } else {
            even = n / 2;
            odd = n / 2;
        }

        // Calculate power of 5 and power of 4 using modular exponentiation
        long long temp1 = powMod(5, even, MOD);
        long long temp2 = powMod(4, odd, MOD);

        // Multiply the results and take modulo
        ans = (ans * temp1 * temp2) % MOD;

        return ans;
    }

private:
    long long powMod(long long base, long long exp, long long mod) {
        long long result = 1;
        base = base % mod;

        while (exp > 0) {
            // If exp is odd, multiply base with result
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }

            // exp must be even now
            exp = exp >> 1; // equivalent to exp /= 2
            base = (base * base) % mod;
        }

        return result;
    }
};
