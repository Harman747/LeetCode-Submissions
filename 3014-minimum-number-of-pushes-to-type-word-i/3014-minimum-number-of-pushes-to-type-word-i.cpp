class Solution {
public:
    int minimumPushes(string word) {
        
        int press = 1 , ans = 0 , n = word.length();
        
        if(n < 8){
            return n;
        }

        while(n > 0){
            
            int taken_number_to_press = min(n,8);

            ans += (press * taken_number_to_press);
            
            n -= taken_number_to_press;
            
            press++;
        }
        
        return ans;
    }
};