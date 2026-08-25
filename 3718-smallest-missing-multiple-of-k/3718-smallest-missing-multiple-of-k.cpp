class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        
        vector<bool> v(101 , false);
        int x = k;

        for(int i = 0 ; i < nums.size() ; i++){
            v[nums[i]] = true;
        }

        while(x < v.size() && v[x]){
            x += k;
        }

        return x;
    }
};