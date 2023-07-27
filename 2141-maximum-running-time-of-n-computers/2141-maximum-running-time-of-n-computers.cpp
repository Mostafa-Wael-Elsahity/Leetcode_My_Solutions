class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long left=1,right=0,mid,sum=0,extra;
        for(auto battery:batteries) sum+=battery;
        right=sum/n;
        while(left<right){
            mid=right - (right - left) / 2,extra=0;
            for(auto battery:batteries) extra+=min(battery*1ll,mid);
            if(extra>=n*mid) left=mid;
            else right=mid-1;
        }
        return left;
    }
};