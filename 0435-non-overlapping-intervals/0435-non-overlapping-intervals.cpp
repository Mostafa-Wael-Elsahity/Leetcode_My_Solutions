class Solution {
public:
    static bool comp(const vector<int>& a,const vector<int>& b){
        if(a[1]<b[1]||(a[1]==b[1]&&a[0]<b[0])) return 1;
        return 0;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int ans=0,begin=-1e9,n=intervals.size();
        for(auto interval:intervals)
            if(interval[0]<begin) ans++;
            else begin=interval[1];
        return ans;
    }
};