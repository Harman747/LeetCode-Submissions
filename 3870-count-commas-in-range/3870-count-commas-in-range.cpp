class Solution {
public:
    int countCommas(int n) {
        if(n < 1000) return 0;

        int base = 1000 , ans = 1 , comma_count = 1;

        while(base * 1000 < n){
            ans += (base * comma_count);
            base *= 1000;
            comma_count++;
        }

        ans += (abs(base - n) * comma_count);

        return ans;

    }
};