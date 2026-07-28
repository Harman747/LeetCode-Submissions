class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> word_cnt(26 , 0);

        for(int i = 0 ; i < s.length() ; i++){
            word_cnt[(s[i] - 'a')]++;
        }

        string ans = "";
        string ans_last = "";
        string mid = "";

        for(int i = 0 ; i < word_cnt.size() ; i++){
            
            if(word_cnt[i] % 2 == 1){
                mid.push_back('a' + i);
                word_cnt[i]--;
            }

            if(word_cnt[i] > 0){
                int freq = word_cnt[i] / 2;
                ans += string(freq , (char)('a' + i));
            }
        }
        ans_last = ans;
        reverse(ans_last.begin() , ans_last.end());
        return ans + mid + ans_last;
    }
};