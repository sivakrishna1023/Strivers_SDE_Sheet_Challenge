// #include<bits/stdc++.h>
// void solve(vector<vector<int>>& image,int x,int y,int n,int m,int oldcolor,int newcolor){
//     if(x<0 || y<0 || x>=n || y>=m || image[x][y]!=oldcolor) return;
   
//         image[x][y]=newcolor;

//     solve(image,x+1,y,n,m,oldcolor,newcolor);
//     solve(image,x,y+1,n,m,oldcolor,newcolor);
//     solve(image,x-1,y,n,m,oldcolor,newcolor);
//     solve(image,x,y-1,n,m,oldcolor,newcolor);
//     return;
// }
// vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
// {
//     int oldcolor=image[x][y];
//     int n=image.size(),m=image[0].size();
//     solve(image,x,y,n,m,oldcolor,newColor);
//     return image;
//     // Write your code here.
// }
#include<bits/stdc++.h>
// vector<int> dx = {0,0,1,-1};
// vector<int> dy = {1,-1,0,0};

// vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
// {
//     // Write your code here.
//     int val = image[x][y], n= image.size(), m = image[0].size();
//     if(val == newColor) return image;
//     queue<pair<int,int>> pq;
//     image[x][y] =  newColor;
//     pq.push({x,y});
    
//     while(!pq.empty()){
//         int p = pq.front().first, q = pq.front().second,x1,y1;
//         pq.pop();
//         for(int i=0;i<4;i++){
//          x1 = p+dx[i], y1 = q + dy[i];
//          if(x1 <n and x1>=0 and y1<m and y1 >=0 and image[x1][y1] == val){
//            image[x1][y1] =  newColor;
//            pq.push({x1,y1});  
//          } 
//       }   
//     }
//    return image; 
// }

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{   if(image[x][y] == newColor) return image;
    int n=image.size(),m=image[0].size();
    queue<pair<int,int>> q;
    int var=image[x][y];
    image[x][y]=newColor;
    q.push({x,y});
     int dx[]={-1,1,0,0};
     int dy[]={0,0,-1,1};
    while(!q.empty()){
        int x1=q.front().first,y1=q.front().second,nx,ny;q.pop();
       // image[x1][y1]=newColor;
        for(int i=0;i<4;i++){
            nx=x1+dx[i]; ny=y1+dy[i];
            if(nx>=0 && ny>=0 && nx<n && ny<m && image[nx][ny]==var){
                image[nx][ny]=newColor;
                q.push({nx,ny});
            }
        }
    }
    return image;
    // Write your code here.
}
