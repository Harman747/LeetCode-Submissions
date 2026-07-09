class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool> answer;
        vector<int> family(nums.size() + 1 , 0);
        int fam_cnt = 0;

        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i] - nums[i-1] <= maxDiff){
                family[i] = fam_cnt;
            }
            else{
                fam_cnt++;
                family[i] = fam_cnt;
            }
        }

        for(int i = 0 ; i < queries.size() ; i++){
            if(family[queries[i][0]] == family[queries[i][1]]){
                answer.push_back(true);
            }
            else{
                answer.push_back(false);
            }
        }
        return answer;
    }
};