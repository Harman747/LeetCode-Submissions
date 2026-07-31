class Solution {
public:
    bool detectCapitalUse(string word) {
        int upper_cnt = 0;

        for(int i = 0 ; i < word.length() ; i++){
            if(word[i] >= 'A' && word[i] <= 'Z') upper_cnt++;
        }

        if(upper_cnt == 0) return true;

        else if(upper_cnt == 1 && word[0] >= 'A' && word[0] <= 'Z') return true;

        return upper_cnt == word.length(); 
    }
};