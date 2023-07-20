class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        const int DX[8] = {0, 1, 0, -1, 1, -1, 1, -1};
        const int DY[8] = {1, 0, -1, 0, 1, -1, -1, 1};
        int n=board.size(),m=board[0].size();
        vector<vector<int>>ans(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int ctr=0;
                for(int k=0;k<8;k++){
                    int x=i+DX[k],y=j+DY[k];
                    if(x>=0&&x<n&&y<m&&y>=0)
                        ctr+=board[x][y];
                }
                if(board[i][j]){
                    if(ctr<2) ans[i][j]=0;
                    else if(ctr<4) ans[i][j]=1;
                    else ans[i][j]=0;
                }else{
                    if(ctr==3) ans[i][j]=1;
                }
            } 
        }
        board=ans;
    }
};