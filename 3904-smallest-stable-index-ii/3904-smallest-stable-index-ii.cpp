class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int max_val = INT_MIN , min_val = INT_MAX , n = nums.size();

        vector<int> max_till_now(n);
        vector<int> min_till_end(n);

        for(int i = 0 ; i < nums.size() ; i++){
            max_val = max(max_val , nums[i]);
            min_val = min(min_val , nums[n - i - 1]);
            max_till_now[i] = max_val;
            min_till_end[n - i - 1] = min_val;
        }

        for(int i = 0 ; i < nums.size() ; i++){
            if(max_till_now[i] - min_till_end[i] <= k){
                return i;
            }
        } 

        return -1;
    }
};