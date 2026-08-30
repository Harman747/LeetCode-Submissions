class Solution {
public:
    vector<int> getRow(int rowIndex) {

        int row = 1;
        vector<int> cur_row(1 , 1);
        
        while(row <= rowIndex){
            vector<int> new_row;
            new_row.push_back(cur_row[0]);
            for(int i = 0 ; i < cur_row.size() - 1 ; i++){
                new_row.push_back(cur_row[i] + cur_row[i+1]);
            }
            new_row.push_back(cur_row[cur_row.size() - 1]);
            cur_row = new_row;
            row++;
        }
        return cur_row;
    }
};