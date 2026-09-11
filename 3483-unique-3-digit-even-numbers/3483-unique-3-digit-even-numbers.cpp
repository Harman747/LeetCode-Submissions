class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        
        unordered_set<string> st;

        for(int i = 0 ; i < digits.size() ; i++){
            
            if(digits[i] == 0) continue;

            for(int j = 0 ; j < digits.size() ; j++){
            
                if(j == i) continue;

                for(int k = 0 ; k < digits.size() ; k++){
            
                    if(k == i || k == j) continue;
                    if(digits[k] % 2 != 0) continue;
                    string cur_s = to_string(digits[i]) + to_string(digits[j]) + to_string(digits[k]);
                    st.insert(cur_s);
                }
            }
        }
        return st.size();
    }
};