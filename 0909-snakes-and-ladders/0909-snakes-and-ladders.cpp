class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        // reindexing board 
        int n=board.size(),idx=1,step=1,sz;
        bool flip=1;
        unordered_map<int,int>mp;
        unordered_set<int>vis;
        for(int i=n-1;i>=0;i--,flip=!flip){
            if(flip){
                for(int j=0;j<n;j++,step++){
                    mp[step]=board[i][j]>0?board[i][j]:step;
                }
            }
            else{
                for(int j=n-1;j>=0;j--,step++){
                    mp[step]=board[i][j]>0?board[i][j]:step;
                }
            }
        }
        step=0;
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