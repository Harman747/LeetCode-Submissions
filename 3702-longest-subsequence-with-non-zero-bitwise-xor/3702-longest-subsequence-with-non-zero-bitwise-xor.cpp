class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x = nums[0];
        bool all_zero = true;

        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i] != 0) all_zero = false;
            x ^= nums[i];
        }

        if(x != 0) return nums.size();

        if(all_zero) return 0;

        return nums.size() - 1;

    }
};