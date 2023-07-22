class Solution {
public:
    const int dx[8]={1,1,-1,-1,2,2,-2,-2};
    const int dy[8]={2,-2,2,-2,1,-1,1,-1};
    double knightProbability(int n, int k, int row, int column) {
        double totalProbability=0,memo[k+5][n][n];
        memset(memo,0,sizeof memo);
        function<double(int,int,int)> calcDP=[&](int moves,int i,int j)->double{
            if(!moves) return 1;
            double &res=memo[moves][i][j];
            if(res!=0) return res;
            for(int k=0;k<8;k++){
                int x=i-dx[k],y=j-dy[k];
                if(x<n&&x>=0&&y<n&&y>=0)
                    res+=calcDP(moves-1,x,y)/8.0;
            }
            return res;
        };
        return calcDP(k,row,column);
    }
};