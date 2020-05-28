//
//  main.cpp
//  1012
//
//  Created by beonghyunkang on 07/01/2020.
//  Copyright © 2020 beonghyunkang. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

const int MAX=51;
int table[MAX][MAX];
int visited[MAX][MAX];

typedef struct Point{
    int x,y;
}point;

int m,n,k;
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};

bool is_promising(point target){
    
    if(target.x<0||target.x>=m)return false;
    if(target.y<0||target.y>=n)return false;
    if(visited[target.x][target.y])return false;
    if(table[target.x][target.y]==0)return false;
    return true;
}

int bfs(point start)
{
    queue<point> que;
    visited[start.x][start.y]=1;
    que.push(start);
    
    
    while(!que.empty())
    {
        int x=que.front().x;
        int y=que.front().y;
        que.pop();
        
        for(int i=0;i<4;++i)
        {
            int nx,ny;
            nx=x+dx[i];
            ny=y+dy[i];
            if(is_promising({nx,ny}))
            {
                visited[nx][ny]=1;
                
                que.push({nx,ny});
            }
        }
    }
    

    return 1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int c;
    int total=0;
    int x,y;
    
    cin>>c;
    
    
    for(int i=0;i<c;++i)
    {
        cin>>m>>n>>k;
        
        for(int row=0;row<m;++row)
        {
            for(int col=0;col<n;++col)
            {
                table[row][col]=0;
                visited[row][col]=0;
            }
        }
        
        for(int j=0;j<k;++j)
        {
            cin>>x>>y;
            table[x][y]=1;
        }

        
        for(int row=0;row<m;++row)
        {
            for(int col=0;col<n;++col)
            {
                if(table[row][col]==1&&visited[row][col]==0)
                  total=total+bfs({row,col});
            }
        }
        
        cout<<total<<"\n";
        total=0;
    }
        return 0;
}
