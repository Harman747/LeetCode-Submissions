class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        int mini = INT_MAX;
        bool odd_occured = false;

        for(int i = 0 ; i < nums1.size() ; i++){
            mini = min(mini , nums1[i]);
            if(nums1[i] % 2 != 0) odd_occured = true;
        }
        


        if(mini % 2 == 0){
            return false || !odd_occured;
        }

        return true;

        // bool all_odd = true , all_even = true;

        
        // //all odd try by subtract smallest even as (even - odd) = (odd - even) = odd number

        // //all even try by subtract smallest even if num is even or subtract odd if num is odd as (even - even) = (odd - odd) = even number
        
        // for(int i = 0 ; i < nums1.size() ; i++){
        //     int x = nums1[i];

        //     if(x % 2 == 0){
        //         all_odd &= (x - smallest_odd >= 1);
        //     } 

        //     else{
        //         all_even &= (x - smallest_odd >= 1);
        //     } 
        // }

        // return all_odd || all_even;
    }
};