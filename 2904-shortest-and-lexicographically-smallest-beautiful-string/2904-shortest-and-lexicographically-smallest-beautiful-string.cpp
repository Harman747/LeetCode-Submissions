class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";

        int one_cnt = 0;
        int l = 0 , r = 0;

        while(r < s.length()){
            if(s[r] == '1'){
                one_cnt++;
            }
            r++;

            while(one_cnt > k){
                if(s[l] == '1'){
                    one_cnt--;
                }
                l++;
            }

            if(one_cnt == k){

                int st = l;
                while(s[st] == '0') st++;

                string cur_s = s.substr(st , r - st);

                if(ans == "" || ans.length() > cur_s.length() || (ans.length() == cur_s.length() && ans > cur_s)){
                    ans = cur_s;
                }

            }
            
        }
        return ans;
    }
};