class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long num = 0;
        long long d = 1;
        while(n > 0){
            int x = n % 10;
            n /= 10;
            
            if(x > 0){
                sum += x;
                num += (d * x);
                d *= 10;
            }
        }
        return num * sum;
    }
};