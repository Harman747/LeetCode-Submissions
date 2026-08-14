class Solution {
public:

    string get_count(string &s){
        vector<int> count(26 , 0);

        for(int i = 0 ; i < s.length() ; i++){
            count[s[i] - 'a']++;
        }

        string ans = "";

        for(int i = 0 ; i < 26 ; i++){
            if(count[i] > 0){
                ans.push_back(('a' + i));
                ans += to_string(count[i]);
            }
        }
        return ans;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string , vector<int>> group;
        vector<vector<string>> ans;

        for(int i = 0 ; i < strs.size() ; i++){
            string cnt = get_count(strs[i]);
            group[cnt].push_back(i);
        }

        for(auto it : group){
            vector<string> g;
            for(int i = 0 ; i < it.second.size() ; i++){
                g.push_back(strs[it.second[i]]);
            }
            ans.push_back(g);
        }
        return ans;
    }
};