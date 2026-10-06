class Solution {
public:
    int minAddToMakeValid(string s) {
        
        int is_open = 0 , ans = 0;

        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == ')'){
                if(is_open > 0){
                    is_open--;
                    continue;
                }
                else{
                    ans++;
                    continue;
                }
            }
            else{
                is_open++;
            }
        }

        return ans + is_open;

    }
};