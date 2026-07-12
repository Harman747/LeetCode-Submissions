class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        sort(temp.begin() , temp.end());
        unordered_map<int,int> m;

        int rank = 1;

        for(int i = 0 ; i < temp.size() ; i++){
            if(m.find(temp[i]) == m.end())
                m[temp[i]] = rank++;
        }
        
        

        for(int i = 0 ; i < arr.size() ; i++){
            arr[i] = m[arr[i]];
        }

        return arr;
    }
};