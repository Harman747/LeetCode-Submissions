class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        vector<int> idx(n);

        for (int i = 0; i < n; i++)
            idx[i] = i;

        mergeSort(nums, idx, ans, 0, n - 1);

        return ans;
    }

    void mergeSort(vector<int>& nums, vector<int>& idx,
                   vector<int>& ans, int l, int r) {
        if (l >= r)
            return;

        int mid = l + (r - l) / 2;

        mergeSort(nums, idx, ans, l, mid);
        mergeSort(nums, idx, ans, mid + 1, r);

        merge(nums, idx, ans, l, mid, r);
    }

    void merge(vector<int>& nums, vector<int>& idx,
               vector<int>& ans, int l, int mid, int r) {

        vector<int> temp;
        int i = l;
        int j = mid + 1;
        int rightSmaller = 0;

        while (i <= mid && j <= r) {

            if (nums[idx[j]] < nums[idx[i]]) {
                temp.push_back(idx[j]);
                rightSmaller++;
                j++;
            }
            else {
                ans[idx[i]] += rightSmaller;
                temp.push_back(idx[i]);
                i++;
            }
        }

        while (i <= mid) {
            ans[idx[i]] += rightSmaller;
            temp.push_back(idx[i]);
            i++;
        }

        while (j <= r) {
            temp.push_back(idx[j]);
            j++;
        }

        for (int k = 0; k < temp.size(); k++)
            idx[l + k] = temp[k];
    }
};