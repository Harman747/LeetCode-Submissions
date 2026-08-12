class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left = 0 , right = 0;
        int ans = 0;

        unordered_map<int,int> count;

        while(left <= right && right < nums.size()){
            if(count[nums[right]] < k){
                count[nums[right]]++;
                right++;
            }

            else{
                
                int number = nums[right];

                while(count[number] >= k){
                    count[nums[left]]--;
                    left++;
                }

            }
            ans = max(ans , right - left);
        }
        return ans;
    }
};