class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {

        unordered_map<int,int> freq;
        unordered_map<int,int> subarray_count;
        int n = nums.size();

        for(int i = 0 ; i < n ; i++){
            freq[nums[i]]++;
        }

        int ans = -1;

        if(k == 1){
            for(auto it : freq){
                if(it.second == 1){
                    ans = max(ans , it.first);
                }
            }
            return ans;
        }

        if(k == n){
            for(auto it : freq){
                ans = max(ans , it.first);
            }
            return ans;
        }

        int f1 = freq[nums[0]] , f2 = freq[nums[n - 1]];

        if((freq[nums[0]] == n) && k != nums.size()) return -1;

        if(f1 == 1 && f2 != 1){
            return nums[0];
        }

        if(f1 != 1 && f2 == 1){
            return nums[n-1];
        }

        if(f1 != 1 && f2 != 1) return -1;

        return max(nums[0] , nums[nums.size() - 1]);
        
    }
};