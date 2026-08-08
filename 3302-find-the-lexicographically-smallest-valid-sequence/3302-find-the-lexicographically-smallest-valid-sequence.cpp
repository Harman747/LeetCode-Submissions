class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // last[j] = latest index in word1 where word2[j] occurs
        vector<int> last(m, -1);

        int i = n - 1, j = m - 1;

        while (i >= 0 && j >= 0) {
            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }
            i--;
        }

        vector<int> ans;
        bool changed = false;

        j = 0;

        for (i = 0; i < n && j < m; i++) {

            // Exact match: always take it
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            }

            // Use our one allowed mismatch
            else if (!changed &&
                     (j == m - 1 || i < last[j + 1])) {
                ans.push_back(i);
                j++;
                changed = true;
            }
        }

        if (j == m)
            return ans;

        return {};
    }
};