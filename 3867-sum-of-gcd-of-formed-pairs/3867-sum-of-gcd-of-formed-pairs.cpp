class Solution {
public:

    int get_gcd(int a , int b){
        if(b == 0){
            return a;
        }
        return get_gcd(b , a % b);
    }

    long long gcdSum(vector<int>& nums) {

        vector<int> prefix_gcd;
        prefix_gcd.reserve(nums.size());
        
        int maxi = INT_MIN;

        for(int i = 0 ; i < nums.size() ; i++){
            maxi = max(maxi , nums[i]);
            prefix_gcd.push_back(get_gcd(maxi , nums[i]));
        }

        long long sum = 0;
        sort(prefix_gcd.begin() , prefix_gcd.end());
        int n = prefix_gcd.size();

        for(int i = 0 ; i < n / 2 ; i++){
            sum += get_gcd(prefix_gcd[i] , prefix_gcd[n - i - 1]);
        }

        return sum;
    }
};