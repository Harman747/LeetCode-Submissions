class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int first = -1 , second = -1;

        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] >= first){
                second = first;
                first = nums[i];
                continue;
            }

            if(nums[i] > second){
                second = nums[i];
            }

        }

        return (first - 1) * (second - 1);
    }
};