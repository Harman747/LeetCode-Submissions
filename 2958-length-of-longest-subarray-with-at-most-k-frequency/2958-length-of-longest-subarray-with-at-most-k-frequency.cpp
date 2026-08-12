class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left = 0 , right = 0;
        int ans = 0;

        unordered_map<int,int> count;

        while(right < nums.size()){
            count[nums[right]]++;
            while(count[nums[right]] > k){
                count[nums[left]]--;
                left++;
            }
            right++;
            ans = max(ans , right - left);
        }
        return ans;
    }
};