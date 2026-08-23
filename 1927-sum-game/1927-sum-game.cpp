class Solution {
public:
    bool sumGame(string num) {

        int count_lq = 0 , count_rq = 0 , n = num.length();
        int left_sum = 0 , right_sum = 0;

        for(int i = 0 ; i < num.length() ; i++){
            
            if(num[i] != '?'){
                (i < n / 2) ? left_sum+= num[i] - '0' : right_sum+= num[i] - '0';
            }

            else{
                (i < n / 2) ? count_lq++ : count_rq++;
            }
        }
        
        if(abs(count_lq - count_rq) % 2 != 0) return true;

        if(left_sum > right_sum){
            int diff = left_sum - right_sum;
            int q_mark_factor = count_rq - count_lq;
            
            return !(diff == (q_mark_factor/2 * 9));
        }

        int diff = right_sum - left_sum;
        int q_mark_factor = count_lq - count_rq;
        
        return !(diff == (q_mark_factor/2 * 9));

    }
};