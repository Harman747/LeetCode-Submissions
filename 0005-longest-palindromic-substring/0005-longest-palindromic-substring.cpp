class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() <= 1) return s;
        
        string ans = s.substr(0 , 0);

        // Odd length
        for(int i = 0 ; i < s.length() - 1; i++){
            int ind = 1;

            while(i - ind >= 0 && i + ind < s.length()){
                if(s[i + ind] == s[i - ind]){
                    ind++;
                }
                else{
                    string cur_ans = s.substr(i - ind + 1, 2 * ind - 1);

                    if(ans == ""){
                        ans = cur_ans;
                    }
                    else{
                        ans = (cur_ans.length() > ans.length()) ? cur_ans : ans;
                    }

                    break;
                }
            }

            // Expansion reached boundary
            if(i - ind < 0 || i + ind >= s.length()){
                string cur_ans = s.substr(i - ind + 1, 2 * ind - 1);

                if(ans == "" || cur_ans.length() > ans.length())
                    ans = cur_ans;
            }
        }

        // Even length
        for(int i = 0; i < s.length() - 1; i++){
            int ind = 0;

            while(i - ind >= 0 && i + 1 + ind < s.length()){
                if(s[i + 1 + ind] == s[i - ind]){
                    ind++;
                }
                else{
                    string cur_ans = s.substr(i - ind + 1, 2 * ind);

                    if(ans == ""){
                        ans = cur_ans;
                    }
                    else{
                        ans = (cur_ans.length() > ans.length()) ? cur_ans : ans;
                    }

                    break;
                }
            }

            // Expansion reached boundary
            if(i - ind < 0 || i + 1 + ind >= s.length()){
                string cur_ans = s.substr(i - ind + 1, 2 * ind);

                if(ans == "" || cur_ans.length() > ans.length())
                    ans = cur_ans;
            }
        }

        return ans;
    }
};