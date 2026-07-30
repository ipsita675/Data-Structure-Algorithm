class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        //highest peak should be min
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({grid[0][0],{0,0}});

        vector<vector<bool>>vis(n,vector<bool>(n,false));

        int dx[4]={1,0,-1,0};
        int dy[4]={0,-1,0,1};

        while(!pq.empty()){
            int t=pq.top().first;
            auto [x,y]=pq.top().second;
            pq.pop();

            if(vis[x][y])continue;
            vis[x][y]=true;

            if(x==n-1 && y==n-1)return t;

            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];

                if(nx<n && ny<n && nx>=0 && ny>=0 && !vis[nx][ny]){
                    int h=max(t,grid[nx][ny]);
                    pq.push({h,{nx,ny}});
                }
            }
        }

        return -1;
    }
};