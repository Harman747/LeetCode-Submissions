class Solution {
public:
    
    // we can also return n directly as from the formula of odd_sum and even_sum we can see only n is the common factor
    // se we can also return n directly

    int gcd(int a , int b){
        if(b == 0) return a;
        return gcd(b , a % b);
    }

    int gcdOfOddEvenSums(int n) {
        if(n == 1){
            return 1;
        }

        int odd_sum = (n * n);
        int even_sum = (n*(n+1));

        return gcd(odd_sum , even_sum);

    }
};