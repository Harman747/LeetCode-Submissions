class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int maxi = INT_MIN;
        for(int i = 0 ; i < nums.size() ; i++){
            maxi = max(maxi , nums[i]);
        }
        vector<int> hihi(maxi + 1 , 0);

        for(int i = 0 ; i < nums.size() ; i++){
            hihi[nums[i]]++;
        }

        int ans = maxi + 1;

        for(int i = 0 ; i < hihi.size() ; i++){
            if(hihi[i] == 0){
                ans = i;
                break;
            }
        }
        return ans;
    }
};