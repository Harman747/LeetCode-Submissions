class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin() , nums.end());

        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i] != nums[i-1] + 1){
                int j = nums[i-1] + 1;
                while(j < nums[i]){
                    ans.push_back(j++);
                }
            }
        }
        return ans;
    }
};