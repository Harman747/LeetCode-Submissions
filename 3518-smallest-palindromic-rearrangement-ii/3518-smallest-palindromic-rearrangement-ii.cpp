class Solution {
public:
    long long LIMIT;

    long long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        r = min(r, n - r);

        __int128 ans = 1;

        for (int i = 1; i <= r; i++) {
            ans = ans * (n - r + i) / i;
            if (ans >= LIMIT)
                return LIMIT;
        }

        return (long long)ans;
    }

    long long countWays(vector<int>& cnt) {
        int rem = 0;
        for (int x : cnt) rem += x;

        long long ways = 1;

        for (int x : cnt) {
            if (x == 0) continue;

            ways *= nCr(rem, x);

            if (ways >= LIMIT)
                return LIMIT;

            rem -= x;
        }

        return ways;
    }

    string smallestPalindrome(string s, int k) {
        LIMIT = k + 1;

        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] & 1)
                mid = 'a' + i;
            cnt[i] /= 2;
        }

        if (countWays(cnt) < k)
            return "";

        string left = "";

        int len = s.size() / 2;

        for (int pos = 0; pos < len; pos++) {

            for (int c = 0; c < 26; c++) {

                if (cnt[c] == 0)
                    continue;

                cnt[c]--;

                long long ways = countWays(cnt);

                if (ways >= k) {
                    left.push_back('a' + c);
                    break;
                }

                k -= ways;
                cnt[c]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        if (mid)
            return left + mid + right;

        return left + right;
    }
};