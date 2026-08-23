class Solution {
public:
    bool sumGame(string num) {

        int count_lq = 0 , count_rq = 0 , n = num.length();
        int left_sum = 0 , right_sum = 0;

        for(int i = 0 ; i < num.length() ; i++){
            
            if(num[i] != '?'){
                (i < n / 2 ? left_sum : right_sum) += num[i] - '0';
            }

            else{
                (i < n / 2) ? count_lq++ : count_rq++;
            }
        }
        
        int dif_q = abs(count_lq - count_rq);

        if(dif_q % 2 == 1) return true;
        
        if(left_sum > right_sum) return !(left_sum - right_sum == (count_rq - count_lq) / 2 * 9);
        
        return !(right_sum - left_sum == (count_lq - count_rq) / 2 * 9);
    }
};