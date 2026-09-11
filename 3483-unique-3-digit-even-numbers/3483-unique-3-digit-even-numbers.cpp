class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        
        unordered_set<string> st;

        for(int i = 0 ; i < digits.size() ; i++){
            
            if(digits[i] == 0) continue;
            string cur_s = "";

            cur_s.push_back(digits[i]);

            for(int j = 0 ; j < digits.size() ; j++){
            
                if(j == i) continue;
                
                cur_s.push_back(digits[j]);

                for(int k = 0 ; k < digits.size() ; k++){
            
                    if(k == i || k == j) continue;
                    if(digits[k] % 2 != 0) continue;

                    cur_s.push_back(digits[k]);
                    st.insert(cur_s);
                    cur_s.pop_back();
                }
                cur_s.pop_back();
            }
        }
        return st.size();
    }
};