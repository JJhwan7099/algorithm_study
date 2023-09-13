#include<iostream>
#include<queue>
using namespace std;
#define FOR(i,N) for(int i=1;i<=N;i++)
int N,M;
int graph[20][20];
int Ox,Oy;
bool Rcheck; // R이 O에 들어갔는지
bool Bcheck; // B가 O에 들어갔는지
void print(int rx, int ry, int bx, int by)
{
    cout << "***start print***\n";
    FOR(i,N)
    {   
        FOR(j,M)
        {
            if(rx==i && ry==j) cout << "R";
            else if(bx==i && by==j) cout << "B";
            else if(graph[i][j]==-1) cout << "#";
            else if(i==Ox && j==Oy) cout << "O";
            else cout << ".";
         }
        cout << '\n';
    }
    cout << '\n';
}
struct ball
{
    int color, x, y;
};
pair<int,int> move(ball b, string way,int X, int Y)
{
    if(way == "u")//위로 기울임
    {
        int x = b.x;
        int y = b.y;
        int color = b.color;
        while(true)
        {
            if(X==Ox && Y == Oy)
            {
                X = -1; Y = -1;
            }
            if(graph[x-1][y]==0)
            {
                return {x-1,y};
            }
            else if(graph[x-1][y]!=-1 && !(x-1==X && y==Y))
            {
                x--;
            }
            else return {x,y};
        }
    }
    if(way == "d")
    {
        int x = b.x;
        int y = b.y;
        int color = b.color;
        
        while(true)
        {
            if(X==Ox && Y == Oy)
            {
                X = -1; Y = -1;
            }
            if(graph[x+1][y]==0)
            {
                return {x+1,y};
            }
            else if(graph[x+1][y]!=-1 && !(x+1==X && y==Y))
            {
                x++;
            }
            else return {x,y};
        }
    }
    if(way == "r")
    {
        int x = b.x;
        int y = b.y;
        int color = b.color;
        
        while(true)
        {
            if(X==Ox && Y == Oy)
            {
                X = -1; Y = -1;
            }
            if(graph[x][y+1]==0)
            {
                return {x,y+1};
            }
            else if(graph[x][y+1]!=-1 && !(x==X && y+1==Y))
            {
                y++;
            }
            else return {x,y};
        }
    }
    if(way == "l")
    {
        int x = b.x;
        int y = b.y;
        int color = b.color;
        while(true)
        {
            if(X==Ox && Y == Oy)
            {
                X = -1; Y = -1;
            }
            if(graph[x][y-1]==0)
            {
                return {x,y-1};
            }
            else if(graph[x][y-1]!=-1 && !(x==X && y-1==Y))
            {
                y--;
            }
            else return {x,y};
        }
    }
}
void bfs(ball R, ball B)
{
    int visit[20][20][20][20];
    visit[R.x][R.y][B.x][B.y] = 1;
    queue<pair<pair<ball,ball>,int>> q;
    q.push({{R,B},0});
    while(q.size()>0)
    {
        int rx = q.front().first.first.x;
        int ry = q.front().first.first.y;
        int bx = q.front().first.second.x;
        int by = q.front().first.second.y;
        int cnt = q.front().second;
        //위로
        if(ry == by)
        {
            if(rx<bx)
            {
                pair<int,int> r = move(q.front().first.first,"u",0,0);
                pair<int,int> b = move(q.front().first.second,"u",r.first,r.second);
                if(r.first == Ox && r.second == Oy)
                {
                    if((b.first != Ox || b.second != Oy) )
                    {
                        if(cnt+1>10) cout << "-1";
                        else cout << cnt+1;
                        return;
                    }
                }else if(!(b.first == Ox && b.second == Oy) && visit[r.first][r.second][b.first][b.second]==0){
                    visit[r.first][r.second][b.first][b.second] = 1;
                    ball br; br.x = r.first; br.y = r.second;
                    ball bb; bb.x = b.first; bb.y = b.second;
                    q.push({{br,bb},cnt + 1});
                }
            }else{
                pair<int,int> b = move(q.front().first.second,"u",0,0);
                pair<int,int> r = move(q.front().first.first,"u",b.first,b.second);
                if(r.first == Ox && r.second == Oy)
                {
                    if((b.first != Ox || b.second != Oy) )
                    {
                        if(cnt+1>10) cout << "-1";
                        else cout << cnt+1;
                        return;
                    }
                }else if(!(b.first == Ox && b.second == Oy) && visit[r.first][r.second][b.first][b.second]==0){
                    visit[r.first][r.second][b.first][b.second] = 1;
                    ball br; br.x = r.first; br.y = r.second;
                    ball bb; bb.x = b.first; bb.y = b.second;
                    q.push({{br,bb},cnt + 1});
                }
            }
        }else{
            pair<int,int> r = move(q.front().first.first,"u",0,0);
            pair<int,int> b = move(q.front().first.second,"u",0,0);
            if(r.first == Ox && r.second == Oy)
            {
                if((b.first != Ox || b.second != Oy) )
                {
                    if(cnt+1>10) cout << "-1";
                    else cout << cnt+1;
                    return;
                }
            }else if(!(b.first == Ox && b.second == Oy) && visit[r.first][r.second][b.first][b.second]==0){
                visit[r.first][r.second][b.first][b.second] = 1;
                ball br; br.x = r.first; br.y = r.second;
                ball bb; bb.x = b.first; bb.y = b.second;
                q.push({{br,bb},cnt + 1});
            }
        }
        //아래로
        if(ry == by)
        {
            if(rx>bx)
            {
                pair<int,int> r = move(q.front().first.first,"d",0,0);
                pair<int,int> b = move(q.front().first.second,"d",r.first,r.second);
                if(r.first == Ox && r.second == Oy)
                {
                    if((b.first != Ox || b.second != Oy) )
                    {
                        if(cnt+1>10) cout << "-1";
                        else cout << cnt+1;
                        return;
                    }
                }else if(!(b.first == Ox && b.second == Oy) && visit[r.first][r.second][b.first][b.second]==0){
                    visit[r.first][r.second][b.first][b.second] = 1;
                    ball br; br.x = r.first; br.y = r.second;
                    ball bb; bb.x = b.first; bb.y = b.second;
                    q.push({{br,bb},cnt + 1});
                }
            }else{
                pair<int,int> b = move(q.front().first.second,"d",0,0);
                pair<int,int> r = move(q.front().first.first,"d",b.first,b.second);
                if(r.first == Ox && r.second == Oy)
                {
                    if((b.first != Ox || b.second != Oy) )
                    {
                        if(cnt+1>10) cout << "-1";
                        else cout << cnt+1;
                        return;
                    }
                }else if(!(b.first == Ox && b.second == Oy) && visit[r.first][r.second][b.first][b.second]==0){
                    visit[r.first][r.second][b.first][b.second] = 1;
                    ball br; br.x = r.first; br.y = r.second;
                    ball bb; bb.x = b.first; bb.y = b.second;
                    q.push({{br,bb},cnt + 1});
                }
            }
        }else{
            pair<int,int> r = move(q.front().first.first,"d",0,0);
            pair<int,int> b = move(q.front().first.second,"d",0,0);
            if(r.first == Ox && r.second == Oy)
            {
                if((b.first != Ox || b.second != Oy) )
                {
                    if(cnt+1>10) cout << "-1";
                    else cout << cnt+1;
                    return;
                }
            }else if(!(b.first == Ox && b.second == Oy) && visit[r.first][r.second][b.first][b.second]==0){
                visit[r.first][r.second][b.first][b.second] = 1;
                ball br; br.x = r.first; br.y = r.second;
                ball bb; bb.x = b.first; bb.y = b.second;
                q.push({{br,bb},cnt + 1});
            }
        }
        //오른쪽
        if(rx == bx)
        {
            if(ry > by)
            {
                pair<int,int> r = move(q.front().first.first,"r",0,0);
                pair<int,int> b = move(q.front().first.second,"r",r.first,r.second);
                if(r.first == Ox && r.second == Oy)
                {
                    if((b.first != Ox || b.second != Oy) )
                    {
                        if(cnt+1>10) cout << "-1";
                        else cout << cnt+1;
                        return;
                    }
                }else if(!(b.first == Ox && b.second == Oy) && visit[r.first][r.second][b.first][b.second]==0){
                    visit[r.first][r.second][b.first][b.second] = 1;
                    ball br; br.x = r.first; br.y = r.second;
                    ball bb; bb.x = b.first; bb.y = b.second;
                    q.push({{br,bb},cnt + 1});
                }
            }else{
                pair<int,int> b = move(q.front().first.second,"r",0,0);
                pair<int,int> r = move(q.front().first.first,"r",b.first,b.second);
                if(r.first == Ox && r.second == Oy)
                {
                    if((b.first != Ox || b.second != Oy) )
                    {
                        if(cnt+1>10) cout << "-1";
                        else cout << cnt+1;
                        return;
                    }
                }else if(!(b.first == Ox && b.second == Oy) && visit[r.first][r.second][b.first][b.second]==0){
                    visit[r.first][r.second][b.first][b.second] = 1;
                    ball br; br.x = r.first; br.y = r.second;
                    ball bb; bb.x = b.first; bb.y = b.second;
                    q.push({{br,bb},cnt + 1});
                }
            }
        }else{
            pair<int,int> r = move(q.front().first.first,"r",0,0);
            pair<int,int> b = move(q.front().first.second,"r",0,0);
            if(r.first == Ox && r.second == Oy)
            {
                if((b.first != Ox || b.second != Oy) )
                {
                    if(cnt+1>10) cout << "-1";
                    else cout << cnt+1;
                    return;
                }
            }else if(!(b.first == Ox && b.second == Oy) && visit[r.first][r.second][b.first][b.second]==0){
                visit[r.first][r.second][b.first][b.second] = 1;
                ball br; br.x = r.first; br.y = r.second;
                ball bb; bb.x = b.first; bb.y = b.second;
                q.push({{br,bb},cnt + 1});
            }
        }
        //왼쪽
        if(rx == bx)
        {
            if(ry < by)
            {
                pair<int,int> r = move(q.front().first.first,"l",0,0);
                pair<int,int> b = move(q.front().first.second,"l",r.first,r.second);
                if(r.first == Ox && r.second == Oy)
                {
                    if((b.first != Ox || b.second != Oy) )
                    {
                        if(cnt+1>10) cout << "-1";
                        else cout << cnt+1;
                        return;
                    }
                }else if(!(b.first == Ox && b.second == Oy) && visit[r.first][r.second][b.first][b.second]==0){
                    visit[r.first][r.second][b.first][b.second] = 1;
                    ball br; br.x = r.first; br.y = r.second;
                    ball bb; bb.x = b.first; bb.y = b.second;
                    q.push({{br,bb},cnt + 1});
                }
            }else{
                pair<int,int> b = move(q.front().first.second,"l",0,0);
                pair<int,int> r = move(q.front().first.first,"l",b.first,b.second);
                if(r.first == Ox && r.second == Oy)
                {
                    if((b.first != Ox || b.second != Oy) )
                    {
                        if(cnt+1>10) cout << "-1";
                        else cout << cnt+1;
                        return;
                    }
                }else if(!(b.first == Ox && b.second == Oy) && visit[r.first][r.second][b.first][b.second]==0){
                    visit[r.first][r.second][b.first][b.second] = 1;
                    ball br; br.x = r.first; br.y = r.second;
                    ball bb; bb.x = b.first; bb.y = b.second;
                    q.push({{br,bb},cnt + 1});
                }
            }
        }else{
            pair<int,int> r = move(q.front().first.first,"l",0,0);
            pair<int,int> b = move(q.front().first.second,"l",0,0);
            if(r.first == Ox && r.second == Oy)
            {
                if((b.first != Ox || b.second != Oy) )
                {
                    if(cnt+1>10) cout << "-1";
                    else cout << cnt+1;
                    return;
                }
            }else if(!(b.first == Ox && b.second == Oy) && visit[r.first][r.second][b.first][b.second]==0){
                visit[r.first][r.second][b.first][b.second] = 1;
                ball br; br.x = r.first; br.y = r.second;
                ball bb; bb.x = b.first; bb.y = b.second;
                q.push({{br,bb},cnt + 1});
            }
        }
        q.pop();
    }
    cout << "-1";
}
int main()
{
    fill(&graph[0][0],&graph[20][20],-1);
    cin >> N >> M;
    ball R, B;
    FOR(i,N)FOR(j,M)
    {
        char c; cin >> c;
        if(c=='#') graph[i][j] = -1;
        else if(c=='O') 
        {
            graph[i][j] = 0;
            Ox = i; Oy = j;
        }
        else if(c=='.') graph[i][j] = 1; 
        else if(c=='R')
        {
            graph[i][j] = 2; // R공이 2
            R.color = 2;
            R.x = i;
            R.y = j;
        }
        else if(c=='B') 
        {
            graph[i][j] = 3; // B공이 3
            B.color = 3;
            B.x = i;
            B.y = j;
        }
    }
    bfs(R,B);
}