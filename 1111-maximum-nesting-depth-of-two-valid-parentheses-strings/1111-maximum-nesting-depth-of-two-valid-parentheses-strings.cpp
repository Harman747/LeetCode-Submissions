class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int max_depth = 0;
        vector<int> depth;
        for(int i = 0 ; i < seq.length() ; i++){
            if(seq[i] == '('){
                depth.push_back(max_depth++ % 2);
            }
            else if(seq[i] == ')'){
                depth.push_back(--max_depth % 2);
            }
        }
        return depth;
    }
};