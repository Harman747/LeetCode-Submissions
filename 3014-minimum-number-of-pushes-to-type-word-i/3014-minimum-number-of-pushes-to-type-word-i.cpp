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
            if(n > 8){
                n -= 8;
                ans += (press * 8);
                press++;
            }

            else{
                ans += (press * n);
                n = 0;
                press++;
            }
        }
        return ans;
    }
};