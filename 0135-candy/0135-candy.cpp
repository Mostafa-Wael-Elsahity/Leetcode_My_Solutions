class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size(),sum=1,lastPos=0,value=1,mxV=1;
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]) sum+=++value,lastPos=i,mxV=value;
            else if(ratings[i-1]==ratings[i]) value=1,sum++,lastPos=i,mxV=value;
            else {
                sum+=i-lastPos;
                if(i-lastPos==mxV) sum++,mxV++;
                value=1;
            }
        }
        return sum;
    }
};