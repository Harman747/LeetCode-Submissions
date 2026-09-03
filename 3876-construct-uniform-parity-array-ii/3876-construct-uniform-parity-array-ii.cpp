class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int smallest_odd = INT_MAX;

        for(int i = 0 ; i < nums1.size() ; i++){
            if(nums1[i] % 2 != 0){
                smallest_odd = min(smallest_odd , nums1[i]);
            }
        }
        
        bool all_odd = true , all_even = true;

        
        //all odd try by subtract smallest even as (even - odd) = (odd - even) = odd number

        //all even try by subtract smallest even if num is even or subtract odd if num is odd as (even - even) = (odd - odd) = even number
        
        for(int i = 0 ; i < nums1.size() ; i++){
            int x = nums1[i];

            if(x % 2 == 0){
                all_odd &= (x - smallest_odd >= 1);
            } 

            else{
                all_even &= (x - smallest_odd >= 1);
            } 
        }

        return all_odd || all_even;
    }
};