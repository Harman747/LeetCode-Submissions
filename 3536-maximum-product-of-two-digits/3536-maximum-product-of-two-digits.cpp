class Solution {
public:
    int maxProduct(int n) {

        int first = -1 , second = -1;

        while(n > 0){
            int d = n % 10;
            if(d >= first){
                second = first;
                first = d;
                n /= 10;
                continue;
            }
            if(d > second){
                second = d;
            }
            n /= 10;
        }

        return first * second;
        
    }
};