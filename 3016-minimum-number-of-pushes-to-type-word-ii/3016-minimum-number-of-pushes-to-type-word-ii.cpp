class Solution {
public:
    int minimumPushes(string word) {
        vector<int> count(26 , 0);

        for(int i = 0 ; i < word.length() ; i++){
            count[word[i] - 'a']++;
        }

        sort(count.begin() , count.end());

        int k = 1;
        int ind = 25;
        int ans = 0;
        int p = 1;

        while(ind >= 0){
            ans += (p * count[ind]);

            if(count[ind] > 0){
                k++;
            }

            if(k == 9){
                k = 1;
                p++;
            }

            ind--;

        }

        return ans;
    }
};