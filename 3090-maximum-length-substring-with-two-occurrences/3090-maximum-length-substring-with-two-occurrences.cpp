class Solution {
public:
    int maximumLengthSubstring(string s) {
        int left = 0 , right = 0;
        unordered_map<char , int> m;
        int ans = 0;

        while(right < s.length()){
            if(m[s[right]] >= 2){
                while(m[s[right]] >= 2){
                    m[s[left]]--;
                    left++;
                }
            }
            else{
                m[s[right]]++;
                right++;
            }
            ans = max(ans , right - left);
        }

        return ans;
    }
};