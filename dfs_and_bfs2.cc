class Solution {
public:
    int m,n;
    vector<vector<char>> grid2;
    vector<pair<int,int>> dirs;

    bool valid(int x, int y){
        if(x< m && x >= 0 && y < n && y >= 0) return true;
        return false;
    }
    bool visited[300][300];
    void dfs(pair<int,int> s){
        if(visited[s.first][s.second]) return;
        visited[s.first][s.second] = 1;
        for(auto i: dirs){
            int x =  s.first + i.first;
            int y = s.second + i.second;
            if(!valid(x,y) || visited[x][y] || grid2[x][y] == '0') continue;
            dfs(pair<int,int>(x,y));
        }
        
    }
    
    void bfs(pair<int,int> s){
        if(visited[s.first][s.second]) return;
        visited[s.first][s.second] = 1;
        queue<pair<int,int>> q;
        q.push(s);
        while(!q.empty()){
            pair<int,int> f = q.front();
            q.pop();
            for(auto i: dirs){
                int x =  f.first + i.first;
                int y = f.second + i.second;
                if(!valid(x,y) || visited[x][y] || grid2[x][y] == '0') continue;
                visited[x][y] = 1;
                q.push(pair<int,int>(x,y));
            }
        }
    }
    
    

    int numIslands(vector<vector<char>>& grid) {
        grid2 = grid;
        int ans = 0;
        m = grid.size();
        n = grid[0].size();
        dirs.push_back(pair<int,int>(0,1));
        dirs.push_back(pair<int,int>(1,0));
        dirs.push_back(pair<int,int>(0,-1));
        dirs.push_back(pair<int,int>(-1,0));
        for(int i = 0; i< m ; i++){
            for(int j = 0; j < n; j++){
                pair<int,int> wa(i,j);
                if(!visited[i][j] && grid[i][j] == '1') {
                    dfs(pair<int,int>(i,j));
                    ans++;
                }
            }
        }
        return ans;
    }
};