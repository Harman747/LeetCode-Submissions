class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        if(nums.size() < 3){
            return nums.size();
        }

        int ans = 1;
         
        while(ans <= nums.size()){
            ans *= 2;
        }

        return ans;
    }
};