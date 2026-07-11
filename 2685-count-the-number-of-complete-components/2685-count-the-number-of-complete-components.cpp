class Solution {
public:

    void dfs(unordered_map<int , vector<int>> & m , int val , vector<bool>& visited , int & edges , int & nodes){
        visited[val] = true;
        nodes++;

        if(m.find(val) == m.end()){
            return;
        }

        vector<int> adj = m[val];

        edges += adj.size();

        for(int i = 0 ; i < adj.size() ; i++){
            if(!visited[adj[i]])
                dfs(m , adj[i] , visited , edges , nodes);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int , vector<int>> m;
        for(int i = 0 ; i < edges.size() ; i++){
            m[edges[i][0]].push_back(edges[i][1]);
            m[edges[i][1]].push_back(edges[i][0]);
        }

        int ans = 0;
        vector<bool> visited(n , false);

        for(int i = 0 ; i < n ; i++){
            int nodes = 0 , edges = 0;
            if(!visited[i]){
                dfs(m , i , visited , edges , nodes);
                edges /= 2;
                if(edges == ((nodes * (nodes - 1))/2)){
                    ans++;
                }
            }
        }

        return ans;
    }
};