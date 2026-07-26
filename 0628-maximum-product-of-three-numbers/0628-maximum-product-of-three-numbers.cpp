class Solution {
public:
    int maximumProduct(vector<int>& nums) {

        int f_min = INT_MAX , s_min = INT_MAX , f_max = INT_MIN , s_max = INT_MIN , t_max = INT_MIN ;

        for(int i = 0 ; i < nums.size() ; i++){
            int d = nums[i];

            if(d >= f_max){
                t_max = s_max;
                s_max = f_max;
                f_max = d;
            }

            else if(d >= s_max){
                t_max = s_max;
                s_max = d;
            }

            else if(d > t_max){
                t_max = d;
            }

            if(d <= f_min){
                s_min = f_min;
                f_min = d;
            }

            else if(d < s_min){
                s_min = d;
            }

        }
        return max((s_min * f_min * f_max) , (f_max * s_max * t_max));
    }
};