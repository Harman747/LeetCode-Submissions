class Solution {
public:



    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size() , m = grid[0].size();

        for(int t = 0 ; t < k ; t++){
            
            int elem = grid[0][0];
            int row = 0 , col = 0;

            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < m ; j++){
                    
                    row = (j == m - 1) ? (row + 1) % n : row;
                    col = (col + 1) % m;

                    swap(elem , grid[row][col]);
                }
            }

        }
        return grid;
    }
};