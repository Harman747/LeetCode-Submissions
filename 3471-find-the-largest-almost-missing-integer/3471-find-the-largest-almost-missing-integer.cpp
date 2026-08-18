class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {

        unordered_map<int,int> freq;
        unordered_map<int,int> subarray_count;

        for(int i = 0 ; i < nums.size() ; i++){
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

        if(k == nums.size()){
            for(auto it : freq){
                ans = max(ans , it.first);
            }
            return ans;
        }

        int f1 = freq[nums[0]] , f2 = freq[nums[nums.size() - 1]];

        if(f1 == 1 && f2 != 1){
            return nums[0];
        }

        if(f1 != 1 && f2 == 1){
            return nums[nums.size() - 1];
        }

        if((freq[nums[0]] == nums.size()) && k != nums.size()) return -1;

        return max(nums[0] , nums[nums.size() - 1]);
        
    }
};