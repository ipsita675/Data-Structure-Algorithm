class Solution {
public:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    bool dfs(int i,int j,int k,vector<vector<char>>& board,string& word){
        int m=board.size();
        int n=board[0].size();

        k++;
        if(k==word.size())return true;
        char og=board[i][j];
        board[i][j]='#';
        for(int d=0;d<4;d++){
            int ni=i+dx[d];
            int nj=j+dy[d];

            if(ni>=0 && nj>=0 && ni<m && nj<n && board[ni][nj]!='#' && 
            board[ni][nj]==word[k]){
                if(dfs(ni,nj,k,board,word))return true;
            }
        }
        board[i][j]=og;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(dfs(i,j,0,board,word))return true;
                }
            }
        }

        return false;
    }
};