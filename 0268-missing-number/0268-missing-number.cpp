class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xr = nums.size();

        for(int i = 0 ; i < nums.size() ; i++){
            xr ^= i;
            xr ^= nums[i];
        }

        return xr;
    
    }
};