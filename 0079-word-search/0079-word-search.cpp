class Solution {
public:
    bool dfs(int i,int j,int c,vector<vector<char>>& board, string word){
        int m=board.size();
        int n=board[0].size();

        if(c==word.size())return true;
        if(i<0 || i>=m || j<0 || j>=n || board[i][j]!=word[c])return false;

        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};

        char og=board[i][j];
        board[i][j]='#';
        for(int d=0;d<4;d++){
            if(dfs(i+dx[d],j+dy[d],c+1,board,word)){
                board[i][j]=og;
                return true;
            }
        }

        board[i][j]=og;
        return false;;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(word[0]==board[i][j]){
                    if(dfs(i,j,0,board,word))return true;
                }
            }
        }

        return false;
    }
};