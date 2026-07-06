class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        auto cmp = [](const vector<int>& a ,const vector<int> & b){

            if(a[0] == b[0]){
                return a[1] > b[1];
            }
            return a[0] < b[0];
        };

        sort(intervals.begin() , intervals.end() , cmp);

        int max_r = INT_MIN , ans = intervals.size();
        
        for(int i = 0 ; i < intervals.size() ; i++){
            if(intervals[i][1] <= max_r){
                ans--;
            }
            max_r = max(max_r , intervals[i][1]);
        }
        return ans;
    }
};