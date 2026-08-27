class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        if(intervals.size() == 0){
            intervals.push_back(newInterval);
            return intervals;
        }

        vector<vector<int>> ans;

        int s = 0 , e = intervals.size() - 1 , index = -1;

        while(s <= e){
            int mid = s + (e - s) / 2;
            
            if(intervals[mid][1] < newInterval[0]){
                s = mid + 1;
            }

            else{
                index = mid;
                e = mid - 1;
            }
        }

        if(index == -1){
            intervals.push_back(newInterval);
            return intervals;
        }

        if(intervals[index][0] > newInterval[1]){
            intervals.push_back(newInterval);
            sort(intervals.begin() , intervals.end());
            return intervals;
        }

        intervals[index][1] = max(intervals[index][1] , newInterval[1]);
        intervals[index][0] = min(intervals[index][0] , newInterval[0]);

        int k = index + 1;
        unordered_set<int> st;
            
        while(k < intervals.size()){
            if(intervals[index][1] >= intervals[k][0]){
                intervals[index][1] = (intervals[k][1] > intervals[index][1]) ? intervals[k][1] : intervals[index][1];
                st.insert(k);
            }
            k++;
        }

        for(int i = 0 ; i < intervals.size() ; i++){
            if(st.find(i) == st.end()){
                ans.push_back(intervals[i]);
            }
        }
             
        return ans;

    }
};