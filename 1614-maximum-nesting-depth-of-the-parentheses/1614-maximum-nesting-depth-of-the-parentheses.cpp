class Solution {
public:
    int maxDepth(string s) {
        int max_depth = 0;
        int ans = 0;

        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == '(') {
                max_depth++;
                ans = max(ans , max_depth);
            }
            if(s[i] == ')') max_depth--;
            
        }

        return ans;
    }
};