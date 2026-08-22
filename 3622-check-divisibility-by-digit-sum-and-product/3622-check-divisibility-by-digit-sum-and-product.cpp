class Solution {
public:
    bool checkDivisibility(int n) {
        long long prod = 1;
        int sum = 0 , x = n;

        while(x > 0){
            int d = x % 10;
            x /= 10;

            sum += d;
            prod *= d;
        }

        return ((n % (sum + prod)) == 0);
    }
};