class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s;

        for(int i = 0 ; i < nums.size() ; i++){
            s.insert(nums[i]);
        }

        int x = k;

        while(s.find(x) != s.end()){
            x += k;
        }

        return x;

    }
};