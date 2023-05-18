class Solution {
public:
    vector<int> adj[2001];
    bool visited[2001];

    bool dfs(int i) {
        if(adj[i].size() == 0) return true;
        if(visited[i]) return false;
        visited[i] = true;
        for(auto j : adj[i]) {
            if(!dfs(j)) return false;
        }
        adj[i].clear();
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto i : prerequisites) {
            adj[i[0]].push_back(i[1]);
        }
        for(int i = 0; i < numCourses; i++) {
            if(!dfs(i)) return false;
        }
        return true;
    }
};