class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size(),l=0,r=m*n-1,mid;
        while(l<=r){
            mid=(r+l)/2;
            int row=mid/m;
            int col=mid%m;
            if(matrix[row][col]==target) return 1;
            else if(matrix[row][col]<target) l=mid+1;
            else r=mid-1;
        }
        return 0;
    }
};