class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        long maxi = INT_MIN;
        for(int i = 0 ; i < nums.size() ; i++){
            maxi = (maxi < nums[i]) ? nums[i] : maxi;
        }

        if(maxi <= 0) return 1;

        vector<bool> is_present(maxi + 1, false);

        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] >= 0) is_present[nums[i]] = true;
        }

        for(int i = 1 ; i < is_present.size() ; i++){
            if(!is_present[i]) return i;
        }
        return maxi + 1;
    }
};