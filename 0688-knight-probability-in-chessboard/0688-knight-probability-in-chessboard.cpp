class Solution {
public:
    const int dx[8]={1,1,-1,-1,2,2,-2,-2};
    const int dy[8]={2,-2,2,-2,1,-1,1,-1};
    double knightProbability(int n, int k, int row, int column) {
        double totalProbability=0;
         vector memo(k + 1, vector (n, vector<double>(n, -1)));
        function<double(int,int,int)> calcDP=[&](int moves,int i,int j)->double{
            if(!moves){// base case 
                return (i==row&&j==column)?1:0;
            }
            double &res=memo[moves][i][j];
            if(res!=-1) return res;
            res=0;
            for(int k=0;k<8;k++){
                int x=i-dx[k],y=j-dy[k];
                if(x<n&&x>=0&&y<n&&y>=0)
                    res+=calcDP(moves-1,x,y)/8.0;
            }
            return res;
        };
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                totalProbability+=calcDP(k,i,j);
            }
        }
        return totalProbability;
    }
};