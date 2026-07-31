class Solution {
public:
    void bfs(vector<vector<char>>& grid,vector<vector<bool>>& vis,int i,int j,int n,int m){
        vis[i][j]=true;
        queue<pair<int,int>>q;
        q.push({i,j});

        int dx[4]={1,0,-1,0};
        int dy[4]={0,1,0,-1};

        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int nr=r+dx[i];
                int nc=c+dy[i];

                if(nr>=0 && nc>=0 && nr<m && nc<n && 
                grid[nr][nc]=='1' && !vis[nr][nc]){

                    vis[nr][nc]=true;
                    q.push({nr,nc});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        int ct=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    bfs(grid,vis,i,j,n,m);
                    ct++;
                }
            }
        }

        return ct;
    }
};