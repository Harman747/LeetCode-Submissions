class Solution {
public:
    int stoneGameIX(vector<int>& stones) {
        vector<int> cnt(3, 0);

        for (int x : stones)
            cnt[x % 3]++;

        // Alice can win if:
        // 1. cnt[0] is even and both cnt[1] and cnt[2] are non-zero
        // 2. cnt[0] is odd and the difference between cnt[1] and cnt[2]
        //    is greater than 2
        if (cnt[0] % 2 == 0)
            return cnt[1] > 0 && cnt[2] > 0;

        return abs(cnt[1] - cnt[2]) > 2;
    }
};