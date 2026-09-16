class Solution {
public:

    const int MOD = 1000000007;

    long long power(long long a, long long b) {
        long long res = 1;

        while (b > 0) {
            if (b & 1)
                res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }

        return res;
    }

    int numberOfSets(int n, int k) {

        long long ans = 1;

        for (int i = n - k; i <= n + k - 1; i++)
            ans = ans * i % MOD;

        long long fact = 1;

        for (int i = 2; i <= 2 * k; i++)
            fact = fact * i % MOD;

        ans = ans * power(fact, MOD - 2) % MOD;

        return (int)ans;

    }
};