class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        if(strs.size() == 0) return "";

        if(strs.size() == 1) return strs[0];
        string ans = "";
        bool is_same = true;
        int ind = 0;
        char c = strs[0][0];

        while(true){
            for(int i = 1 ; i < strs.size() ; i++){
                string temp = strs[i];
                if(ind < temp.length() && temp[ind] == c){
                    continue;
                }
                else{
                    is_same = false;
                    break;
                }
            }
            if(is_same){
                ans.push_back(c);
                ind++;
                if(ind < strs[0].length()){
                    c = strs[0][ind];
                }
                else{
                    return ans;
                }
            } 
            else{
                break;
            }
        }
        return ans;
    }
};