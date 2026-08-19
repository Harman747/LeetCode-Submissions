class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,bool> left_part;
        unordered_map<int,bool> left_mid_part;
        unordered_map<int,bool> right_mid_part;
        unordered_map<int,bool> right_part;

        int ans = 2 * n;
        unordered_set<int> reserved_seats;

        for(int i = 0 ; i < reservedSeats.size() ; i++){
            int r = reservedSeats[i][0];
            int c = reservedSeats[i][1];

            if(c >= 2 && c <= 3){
                left_part[r] = true;
            }

            else if(c >= 4 && c <= 5){
                left_mid_part[r] = true;
            }

            else if(c >= 6 && c <= 7){
                right_mid_part[r] = true;
            }

            else if(c >= 8 && c <= 9){
                right_part[r] = true;
            }

            reserved_seats.insert(r);

        }

        for(auto it : reserved_seats){
            bool l = left_part[it] , r = right_part[it] , lm = left_mid_part[it] , rm = right_mid_part[it];

            bool left_fam = !l && !lm;
            bool right_fam = !r && !rm;
            bool mid_fam = !lm && !rm;

            if(left_fam && right_fam) continue;

            else if(left_fam || right_fam || mid_fam) ans -= 1;

            else ans -= 2;
        }

        return ans;

    }
};