class Solution {
public:
    int maxProduct(int n) {

        int n1 = 1 , n2 = 1;
        vector<int> count(10 , 0);

        while(n > 0){
            count[(n % 10)]++;
            n /= 10;
        }

        int first = -1, second = -1;

        for (int i = 9; i >= 0; i--) {
            if (count[i] == 0) continue;

            if (first == -1) {
                first = i;
                if (count[i] >= 2) {
                    second = i;
                    break;
                }
            } else {
                second = i;
                break;
            }
        }

        return first * second;
        
    }
};