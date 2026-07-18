class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prev_sum(nums.size(), 0);
        prev_sum[0] = nums[0];
        unordered_map<int,int> m;
        m[0] = 1;
        int ans = 0;

        for(int i = 1 ; i < nums.size() ; i++){
            prev_sum[i] = prev_sum[i-1] + nums[i]; 
        }

        for(int i = 0 ; i < prev_sum.size() ; i++){
            int diff = prev_sum[i] - k;
            ans += m[diff];
            m[prev_sum[i]]++;
        }

        return ans;
    }
};