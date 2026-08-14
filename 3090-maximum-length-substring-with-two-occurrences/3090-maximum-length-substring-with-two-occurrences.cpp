class Solution {
public:
    int maximumLengthSubstring(string s) {
        int ans = 0;

        for(int i = 0 ; i < s.length() ; i++){

            unordered_map<char,int> m;
            string cur_s = "";

            for(int j = i ; j < s.length() ; j++){
                char c = s[j];

                if(m[c] >= 2){
                    break;
                }

                else{
                    cur_s.push_back(s[j]);
                    m[c]++;
                }

                ans = (cur_s.length() > ans) ? cur_s.length() : ans;
            }
        }
        return ans;
    }
};