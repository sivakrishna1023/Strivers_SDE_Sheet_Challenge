#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    vector<vector<int>> ans;
    if(intervals.size()==0 || intervals.size()==1) return intervals;
    sort(intervals.begin(),intervals.end());
    vector<int> temp;temp.push_back(intervals[0][0]),temp.push_back(intervals[0][1]);
    for(int i=1;i<intervals.size();i++){
        if(intervals[i][0]<=temp[1]){
            temp[1]=max(temp[1],intervals[i][1]);
        }
        else{
            ans.push_back(temp);
            temp[0]=intervals[i][0];
            temp[1]=intervals[i][1];
        }
    }
    ans.push_back(temp);
    return ans;
    // Write your code here.
}
