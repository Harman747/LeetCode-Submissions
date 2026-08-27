class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        string ans = "";

        for (int i = 0; i < s.size(); i++) {
            int x = target[i] - 'a';

            // Use same character
            if (freq[x] > 0) {
                ans += target[i];
                freq[x]--;
                continue;
            }

            // Try a greater character at current position
            bool found = false;

            for (int j = x + 1; j < 26; j++) {
                if (freq[j] > 0) {
                    ans += char('a' + j);
                    freq[j]--;

                    // Fill remaining characters in sorted order
                    for (int c = 0; c < 26; c++) {
                        while (freq[c] > 0) {
                            ans += char('a' + c);
                            freq[c]--;
                        }
                    }

                    return ans;
                }
            }

            // Can't increase current position.
            // Backtrack through previous positions.
            while (!ans.empty()) {
                int last = ans.back() - 'a';
                ans.pop_back();
                freq[last]++;

                i--;

                if (i < 0)
                    return "";

                int cur = target[i] - 'a';

                for (int j = cur + 1; j < 26; j++) {
                    if (freq[j] > 0) {
                        ans += char('a' + j);
                        freq[j]--;

                        // Fill remaining characters sorted
                        for (int c = 0; c < 26; c++) {
                            while (freq[c] > 0) {
                                ans += char('a' + c);
                                freq[c]--;
                            }
                        }

                        return ans;
                    }
                }
            }

            return "";
        }

        // s's permutation exactly matched target.
        // Need to backtrack to make it strictly greater.
        while (!ans.empty()) {
            int last = ans.back() - 'a';
            ans.pop_back();
            freq[last]++;

            int i = ans.size();
            int cur = target[i] - 'a';

            for (int j = cur + 1; j < 26; j++) {
                if (freq[j] > 0) {
                    ans += char('a' + j);
                    freq[j]--;

                    for (int c = 0; c < 26; c++) {
                        while (freq[c] > 0) {
                            ans += char('a' + c);
                            freq[c]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};