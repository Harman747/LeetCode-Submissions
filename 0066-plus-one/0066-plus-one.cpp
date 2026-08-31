class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;

        int carry = 0;

        for(int i = digits.size() - 1 ; i >= 0 ; i--){
            int num = digits[i];
            if(i == digits.size() - 1){
                num += 1;
            }

            num += carry;

            digits[i] = num % 10;
            carry = num / 10;
        }

        if(carry != 0){
            ans.push_back(carry);
        }

        for(int i = 0 ; i < digits.size() ; i++){
            ans.push_back(digits[i]);
        }

        return ans;
    }
};