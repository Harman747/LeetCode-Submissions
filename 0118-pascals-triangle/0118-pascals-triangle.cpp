class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int row = 1;
        vector<vector<int>> ans;

        vector<int> cur_row(1 , 1);
        
        ans.push_back(cur_row);
        while(row < numRows){
            vector<int> new_row;
            new_row.push_back(cur_row[0]);
            for(int i = 0 ; i < cur_row.size() - 1 ; i++){
                new_row.push_back(cur_row[i] + cur_row[i+1]);
            }
            new_row.push_back(cur_row[cur_row.size() - 1]);
            ans.push_back(new_row);
            cur_row = new_row;
            row++;
        }
        return ans;
    }
};