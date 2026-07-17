class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> cnt(mx + 1, 0);
        for (int x : nums)
            cnt[x]++;

        vector<long long> cntG(mx + 1, 0);

        // cntG[i] = number of pairs having gcd exactly i
        for (int i = mx; i >= 1; i--) {
            long long multiples = 0;

            for (int j = i; j <= mx; j += i) {
                multiples += cnt[j];
                cntG[i] -= cntG[j];
            }

            cntG[i] += multiples * (multiples - 1) / 2;
        }

        // Prefix sum:
        // cntG[i] = number of pairs with gcd <= i
        for (int i = 1; i <= mx; i++)
            cntG[i] += cntG[i - 1];

        vector<int> ans;

        for (long long q : queries) {
            ans.push_back(
                upper_bound(cntG.begin(), cntG.end(), q) - cntG.begin()
            );
        }

        return ans;
    }
};