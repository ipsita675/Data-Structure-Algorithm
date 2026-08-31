class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();

        vector<vector<bool>>vis(m,vector<bool>(n,false));
        queue<pair<int,int>>q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==m-1 || i==0 || j==0 || j==n-1) && board[i][j]=='O'){
                    q.push({i,j});
                    vis[i][j]=true;
                }
            }
        }

        int dr[4]={0,1,0,-1};
        int dc[4]={-1,0,1,0};
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];

                if(nr>=0 && nr<m && nc>=0 && nc<n && 
                !vis[nr][nc] && board[nr][nc]=='O'){
                    vis[nr][nc]=true;
                    q.push({nr,nc});
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }

    }
};