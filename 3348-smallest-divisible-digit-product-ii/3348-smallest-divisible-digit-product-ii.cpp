class Solution {
public:
    const unordered_map<int, unordered_map<int, int>> kFactorCounts{
        {0, {}},
        {1, {}},
        {2, {{2, 1}}},
        {3, {{3, 1}}},
        {4, {{2, 2}}},
        {5, {{5, 1}}},
        {6, {{2, 1}, {3, 1}}},
        {7, {{7, 1}}},
        {8, {{2, 3}}},
        {9, {{3, 2}}},
    };

    string smallestNumber(string num, long long t) {
        auto [primeCount, ok] = getPrimeCount(t);
        if (!ok)
            return "-1";

        auto factorCount = getFactorCount(primeCount);

        if (sumValues(factorCount) > num.size())
            return construct(factorCount);

        auto prefix = getPrimeCount(num);

        int firstZero = num.find('0');
        if (firstZero == string::npos) {
            firstZero = num.size();
            if (isSubset(primeCount, prefix))
                return num;
        }

        int n = num.size();

        for (int i = n - 1; i >= 0; i--) {
            int d = num[i] - '0';

            prefix = subtract(prefix, kFactorCounts.at(d));

            int space = n - 1 - i;

            if (i > firstZero)
                continue;

            for (int nd = d + 1; nd <= 9; nd++) {
                auto need = subtract(primeCount,
                                     add(prefix, kFactorCounts.at(nd)));

                auto req = getFactorCount(need);

                if (sumValues(req) <= space) {
                    string ans = num.substr(0, i);
                    ans.push_back(char('0' + nd));

                    int used = sumValues(req);

                    for (int j = 0; j < space - used; j++)
                        ans.push_back('1');

                    ans += construct(req);

                    return ans;
                }
            }
        }

        factorCount = getFactorCount(primeCount);
        factorCount[1] += (n + 1 - sumValues(factorCount));
        return construct(factorCount);
    }

private:
    pair<unordered_map<int, int>, bool> getPrimeCount(long long t) {
        unordered_map<int, int> cnt;

        for (int p : {2, 3, 5, 7}) {
            while (t % p == 0) {
                cnt[p]++;
                t /= p;
            }
        }

        return {cnt, t == 1};
    }

    unordered_map<int, int> getPrimeCount(const string& s) {
        unordered_map<int, int> cnt;
        for (char c : s) {
            int d = c - '0';
            for (auto& [p, v] : kFactorCounts.at(d))
                cnt[p] += v;
        }
        return cnt;
    }

    unordered_map<int, int> add(unordered_map<int, int> a,
                                const unordered_map<int, int>& b) {
        for (auto& [k, v] : b)
            a[k] += v;
        return a;
    }

    unordered_map<int, int> subtract(unordered_map<int, int> a,
                                     const unordered_map<int, int>& b) {
        for (auto& [k, v] : b)
            a[k] = max(0, a[k] - v);
        return a;
    }

    bool isSubset(const unordered_map<int, int>& need,
                  const unordered_map<int, int>& have) {
        for (auto& [k, v] : need) {
            auto it = have.find(k);
            if (it == have.end() || it->second < v)
                return false;
        }
        return true;
    }

    int sumValues(const unordered_map<int, int>& mp) {
        int s = 0;
        for (auto& [_, v] : mp)
            s += v;
        return s;
    }

    unordered_map<int, int> getFactorCount(
        unordered_map<int, int> cnt) {

        unordered_map<int, int> res;

        int c8 = cnt[2] / 3;
        cnt[2] %= 3;

        int c9 = cnt[3] / 2;
        cnt[3] %= 2;

        int c6 = min(cnt[2], cnt[3]);
        cnt[2] -= c6;
        cnt[3] -= c6;

        int c4 = cnt[2] / 2;
        cnt[2] %= 2;

        res[2] = cnt[2];
        res[3] = cnt[3];
        res[4] = c4;
        res[5] = cnt[5];
        res[6] = c6;
        res[7] = cnt[7];
        res[8] = c8;
        res[9] = c9;

        return res;
    }

    string construct(const unordered_map<int, int>& cnt) {
        string s;
        for (int d = 1; d <= 9; d++) {
            auto it = cnt.find(d);
            if (it != cnt.end())
                s.append(it->second, char('0' + d));
        }
        return s;
    }
};