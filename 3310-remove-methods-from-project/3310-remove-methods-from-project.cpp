class Solution {
public:
    
    void dfs(vector<vector<int>> & adj , int k , vector<bool> &nodes){

        if(!nodes[k]) return;

        nodes[k] = false;

        for(int i = 0 ; i < adj[k].size() ; i++){
            dfs(adj , adj[k][i] , nodes);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);

        for(int i = 0 ; i < invocations.size() ; i++){
            adj[invocations[i][0]].push_back(invocations[i][1]);
        }

        vector<int> ans;
        vector<bool> nodes(n , true);

        dfs(adj , k , nodes);
        
        for(int i = 0 ; i < invocations.size() ; i++){
            if(nodes[invocations[i][0]] && !nodes[invocations[i][1]]){
                for(int i = 0 ; i < n ; i++){
                    ans.push_back(i);
                }
                return ans;
            }
        }
        
        for(int i = 0 ; i < nodes.size() ; i++){
            if(nodes[i]){
                ans.push_back(i);
            }
        }

        return ans;
    }
};