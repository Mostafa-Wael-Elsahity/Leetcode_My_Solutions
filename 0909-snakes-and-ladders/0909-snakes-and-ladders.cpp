class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        // reindexing board 
        int n=board.size(),idx=1,step=0,sz;
        unordered_map<int,int>mp;
        unordered_set<int>vis;
        for(int i=n-1;i>=0;i--){
            int actualRowIdx = (n - i - 1);   //rowIndex from bottom 
            int low = (actualRowIdx * n) + 1, high = low + n - 1;  //range of values in currRow
            int forwardCellIdx = low, reverseCellIdx = high;
            for (int j = 0; j < n; j++)
            {
                int actualCellIdx = (actualRowIdx % 2 == 0)? forwardCellIdx : reverseCellIdx;
                if (board[i][j] != -1) mp[actualCellIdx] = board[i][j];
                else mp[actualCellIdx] = actualCellIdx;
                forwardCellIdx++;
                reverseCellIdx--;
            }
        }
        queue<int>q;
        q.push(1);
        vis.insert(1);
        while(!q.empty()){
            sz=q.size();
            while(sz--){
                int curr=q.front(); q.pop();
                if(curr==n*n) return step;
                for(int i=curr+1;i<=min(curr+6,n*n);i++)
                if(!vis.count(i)){
                    q.push(mp[i]);
                    vis.insert(i);
                }
            }
            step++;
        }
        return -1;
    }
};