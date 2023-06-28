#include<bits/stdc++.h>
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{ 
    queue<pair<pair<int,int>,int>> q;int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push({{i,j},0});
            }else if(grid[i][j]==1) cnt++;
        }
    }
    int val=0,time=0;
    while(!q.empty()){
        auto p=q.front();q.pop();
        int x=p.first.first,y=p.first.second,t=p.second;
        time=max(time,t);
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        for(int i=0;i<4;i++){
            int x1=x+dx[i];
            int y1=y+dy[i];
            if(x1>=0 && y1>=0 && x1<n && y1<m && grid[x1][y1]==1){
                grid[x1][y1]=2;
                q.push({{x1,y1},t+1});
                val++;
            }
        }
    }
    if(val!=cnt) return -1;
    else return time;
    // Write your code here. 
}
