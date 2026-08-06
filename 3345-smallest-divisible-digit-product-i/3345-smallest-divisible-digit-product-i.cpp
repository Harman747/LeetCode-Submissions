class Solution {
public:

    int get_prod(int n){
        if(n == 0) return 0;
        
        int p = 1;

        while(n > 0){
            p *= (n % 10);
            n /= 10;
        }

        return p;
    }

    int smallestNumber(int n, int t) {
        int prod = get_prod(n);
        if(prod % t == 0) return n;

        while(prod % t != 0){
            n++;
            prod = get_prod(n);
        }

        return n;
    }
};