class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<long long> sum(s.length() , 0);
        vector<long long> num(s.length() , 0);
        vector<int> count(s.length() , 0);
        vector<int> ans;
        vector<long long> pow10(s.length() + 1 , 1);

        long long prev_sum = 0;
        long long cur_num = 0;
        int cnt = 0;
        const int mod = 1000000007;

        for(int i = 1 ; i <= s.length() ; i++){
            pow10[i] = pow10[i-1] * 10 % mod;
        }

        for(int i = 0 ; i < s.length() ; i++){
            int d = s[i] - '0';

            if(d > 0){
                cur_num = ((cur_num * 10) + d) % mod;
                prev_sum = (prev_sum + d) % mod;
                cnt++;
            }

            sum[i] = prev_sum;
            num[i] = cur_num;
            count[i] = cnt;
        
        }

        for(int i = 0 ; i < queries.size() ; i++){
            int l = queries[i][0];
            int r = queries[i][1];

            long long right_num = num[r];
            long long left_num = (l == 0) ? 0 : num[l-1];

            int count_right = count[r];
            int count_left = (l == 0) ? 0 : count[l-1];
            
            int p = count[r] - count_left;

            long long right_sum = sum[r];
            long long left_sum = (l == 0) ? 0 : sum[l-1];

            long long actual_num = (right_num - (left_num * pow10[p]) % mod + mod) % mod;
            long long actual_sum = (right_sum - left_sum + mod) % mod;

            long long res = 1LL * actual_num * actual_sum % mod;
            ans.push_back((int)res);

        }
        return ans;
    }
};