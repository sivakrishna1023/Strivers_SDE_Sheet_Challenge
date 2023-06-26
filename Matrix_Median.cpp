int upper_bound(vector<int> vals,int m){
    int low=0,high=vals.size()-1;
    while(low<=high){
        int mid=(low+high)>>1;
        if(vals[mid]<=m) low=mid+1;
        else high=mid-1; 
    }
    return low;
}
int getMedian(vector<vector<int>> &matrix)
{
    int n=matrix.size(),m=matrix[0].size();
    int low=1,high=1e9;
    while(low<=high){
        int mid=(low+high)>>1;int cnt=0;
        for(int i=0;i<n;i++){
                cnt+=upper_bound(matrix[i],mid);
        }
        if(cnt<=(n*m)/2) low=mid+1;
        else high=mid-1;
    }
    return low;
    // Write your code here.
}
