class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if(nums.size() < 3) return 1;
        sort(nums.begin() , nums.end());
        
        int n = nums.size();

        int first_min = nums[0] , second_min = nums[1] , third_min = nums[2] , first_max = nums[n - 1], second_max = nums[n - 2] , third_max = nums[n - 3];

        return max((first_min * second_min * first_max) , (first_max * second_max * third_max));
    }
};