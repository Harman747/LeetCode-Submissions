class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int ind_min = 0 , ind_max = 0 , min_elem = INT_MAX , max_elem = INT_MIN , n = nums.size();
        
        for(int i = 0 ; i < n ; i++){
            if(min_elem > nums[i]){
                min_elem = nums[i];
                ind_min = i + 1;
            }
            if(max_elem < nums[i]){
                max_elem = nums[i];
                ind_max = i + 1;
            }
        }

        int cost_from_left = 0 , cost_from_right = 0 , cost_from_both = 0;

        cost_from_left = max(ind_min , ind_max);
        cost_from_right = n - min(ind_min , ind_max) + 1;
        cost_from_both = min(ind_min , ind_max) + (n - max(ind_min , ind_max)) + 1;

    
        return min(cost_from_left , min(cost_from_right , cost_from_both));
    }
};