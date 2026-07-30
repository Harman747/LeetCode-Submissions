class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        
        if(n <= 8){
            return n;
        }

        int ans = 0;
        int press = 1;

        while(n > 0){
            int  k = min(n , 8);
            ans += (press * k);
            press++;
            n -= k;            
        }

        return ans;
    }
};