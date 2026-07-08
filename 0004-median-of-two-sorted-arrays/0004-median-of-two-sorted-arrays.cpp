class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<float> v(nums1.size()+nums2.size(),0);
        merge(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),v.begin());
        int n=v.size();
        float val=0.0;
        if(n%2==0){
            val = ((v[n/2]+v[(n/2 - 1)]))/2.0;
        }
        else{
            val=v[n/2];
        }
        return val;
    }
};