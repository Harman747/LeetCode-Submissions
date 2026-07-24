class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> s;
        unordered_set<int> ans;

        for(int i = 0 ; i < nums.size() ; i++){
            for(int j = 0 ; j < nums.size() ; j++){
                s.insert(nums[i] ^ nums[j]);
            }
        }

        for(int n1 : nums){
            for(auto n2 : s){
                ans.insert(n1 ^ n2);
            }
        }

        return ans.size();
    }
};