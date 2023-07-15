class Solution {
public:
    int calc(int i,int k,int &n,vector<vector<int>>&events,vector<vector<int>>&memo,vector<int>&search){
        if(i==n) return 0;
        if(!k) return 0;
        int &res=memo[i][k];
        if(~res) return res;
        res=calc(i+1,k,n,events,memo,search);
        int pos=upper_bound(search.begin(),search.end(),events[i][1])-search.begin();
        if(pos>i) res=max(res,events[i][2]+calc(pos,k-1,n,events,memo,search));
        return res;
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        int n=events.size();
        vector<vector<int>>memo(n+1,vector<int>(k+1,-1));
        vector<int>search(n);
        for(int i=0;i<n;i++) search[i]=events[i][0];
        return calc(0,k,n,events,memo,search);
    }
};
