class Solution {
public:
    int m;
    int n;
    int newColor2;
    int oldColor;
    vector<vector<int>> image2;
    int visited[50][50];
    void dfs(int sr,int sc){
        cout<<sr<<" "<<sc<<endl;
        if(visited[sr][sc]) return;
        visited[sr][sc] = 1;
        image2[sr][sc] = newColor2;
        if(sr+1 < m && image2[sr+1][sc] == oldColor) dfs(sr+1 , sc);
        if(sr-1 >= 0 && image2[sr-1][sc] == oldColor) dfs(sr-1 , sc);
        if(sc+1 < n && image2[sr][sc+1] == oldColor) dfs(sr , sc+1);
        if(sc-1 >= 0 && image2[sr][sc-1] == oldColor) dfs(sr , sc-1);
    }
    
    void bfs(int sr,int sc){
        queue<pair<int,int>> q;
        q.push(pair<int,int>(sr,sc));
        while(!q.empty()){
            int sr = q.front().first;
            int sc = q.front().second;
            q.pop();
            if(sr >= m || sr < 0 || sc >= n || sc < 0) continue;
            if(image2[sr][sc] != oldColor || visited[sr][sc]) continue;
            visited[sr][sc] = 1;
            image2[sr][sc] = newColor2;
            q.push(pair<int,int>(sr+1,sc));
            q.push(pair<int,int>(sr-1,sc));
            q.push(pair<int,int>(sr,sc+1));
            q.push(pair<int,int>(sr,sc-1));
            
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        oldColor = image[sr][sc];
        m = image.size();
        n = image[0].size();
        newColor2 = newColor;
        image2 = image;
        bfs(sr,sc);
        return image2;
    }
};