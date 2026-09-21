class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> result(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            int rem = num % k;

            vector<long long> next(k, 0);

            // New subarray: [num]
            next[rem]++;

            // Extend all previous subarrays
            for (int r = 0; r < k; r++) {
                int newRem = (r * rem) % k;
                next[newRem] += dp[r];
            }

            // Add all subarrays ending here to answer
            for (int r = 0; r < k; r++) {
                result[r] += next[r];
            }

            dp = next;
        }

        return result;
    }
};