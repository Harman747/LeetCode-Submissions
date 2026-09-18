class Solution {
    public:

        vector<string> maxNumOfSubstrings(string s) {
                int n = s.size();

                        vector<int> first(26, n);
                                vector<int> last(26, -1);

                                        // First and last occurrence
                                                for (int i = 0; i < n; i++) {
                                                            int c = s[i] - 'a';
                                                                        first[c] = min(first[c], i);
                                                                                    last[c] = i;
                                                                                            }

                                                                                                    vector<pair<int, int>> intervals;

                                                                                                            // Create valid intervals
                                                                                                                    for (int c = 0; c < 26; c++) {

                                                                                                                                if (last[c] == -1)
                                                                                                                                                continue;

                                                                                                                                                            int l = first[c];
                                                                                                                                                                        int r = last[c];
                                                                                                                                                                                    bool valid = true;

                                                                                                                                                                                                for (int i = l; i <= r; i++) {

                                                                                                                                                                                                                int x = s[i] - 'a';

                                                                                                                                                                                                                                // This character started before our interval
                                                                                                                                                                                                                                                if (first[x] < l) {
                                                                                                                                                                                                                                                                    valid = false;
                                                                                                                                                                                                                                                                                        break;
                                                                                                                                                                                                                                                                                                        }

                                                                                                                                                                                                                                                                                                                        // Need to include all occurrences of this character
                                                                                                                                                                                                                                                                                                                                        r = max(r, last[x]);
                                                                                                                                                                                                                                                                                                                                                    }

                                                                                                                                                                                                                                                                                                                                                                if (valid)
                                                                                                                                                                                                                                                                                                                                                                                intervals.push_back({r, l});
                                                                                                                                                                                                                                                                                                                                                                                        }

                                                                                                                                                                                                                                                                                                                                                                                                // Earliest ending interval first
                                                                                                                                                                                                                                                                                                                                                                                                        sort(intervals.begin(), intervals.end());

                                                                                                                                                                                                                                                                                                                                                                                                                vector<string> ans;
                                                                                                                                                                                                                                                                                                                                                                                                                        int prevEnd = -1;

                                                                                                                                                                                                                                                                                                                                                                                                                                for (auto [r, l] : intervals) {

                                                                                                                                                                                                                                                                                                                                                                                                                                            if (l > prevEnd) {
                                                                                                                                                                                                                                                                                                                                                                                                                                                            ans.push_back(s.substr(l, r - l + 1));
                                                                                                                                                                                                                                                                                                                                                                                                                                                                            prevEnd = r;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                }

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        return ans;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        };
