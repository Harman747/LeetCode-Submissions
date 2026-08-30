class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int max_val = INT_MIN , ind_max = 0 , min_val = INT_MAX , ind_min = 0;

        for(int i = 0 ; i < nums.size() ; i++){
            if(min_val > nums[i]){
                min_val = nums[i];
                ind_min = i + 1;
            }
            if(max_val < nums[i]){
                max_val = nums[i];
                ind_max = i + 1;
            }
        }

        int cost_left = max(ind_min , ind_max);
        int cost_right = nums.size() - min(ind_min , ind_max) + 1;
        int cost_both = min(ind_min , ind_max) + (nums.size() - max(ind_min , ind_max)) + 1;

        return min(cost_left , min(cost_right , cost_both));

    }
};