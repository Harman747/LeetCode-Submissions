class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int ans = 0;
        vector<int> freq(10 , 0);
    
        for(int x : digits){
            freq[x]++;
        }

        for(int i = 100 ; i < 1000 ; i += 2){
            int n = i;
            int ones = n % 10; n /= 10;
            int tens = n % 10; n /= 10;
            int hund = n % 10;

            if(ones == tens && tens == hund){
                if(freq[ones] >= 3) ans++;
            }

            else if(ones == tens){
                if(freq[ones] >= 2 && freq[hund] >= 1) ans++;
            }

            else if(tens == hund){
                if(freq[tens] >= 2  && freq[ones] >= 1) ans++;
            }

            else if(ones == hund){
                if(freq[ones] >= 2  && freq[tens] >= 1) ans++;
            }

            else{
                if(freq[ones] > 0 && freq[tens] > 0 && freq[hund] > 0) ans++;
            }
        }
        return ans;
    }
};