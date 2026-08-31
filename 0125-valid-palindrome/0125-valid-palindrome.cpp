class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0 , r = s.length() - 1;

        while(l <= r){
            if(((int)s[l] < 65 || (int)s[l] > 90) && ((int)s[l] < 97 || (int)s[l] > 122) && ((int)s[l] < 48 || (int)s[l] > 57)){
                l++;
                continue;
            }

            if(((int)s[r] < 65 || (int)s[r] > 90) && ((int)s[r] < 97 || (int)s[r] > 122) && ((int)s[r] < 48 || (int)s[r] > 57)){
                r--;
                continue;
            }

            if(tolower(s[l]) != tolower(s[r])){
                return false;
            }

            l++;
            r--;
        }

        return true;
    }
};