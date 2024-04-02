#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N, M, K;
struct Fireball{
    int m,s,d;
};
queue<Fireball> board[51][51];
int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};
void move()
{
    queue<Fireball> sample[51][51];
    FOR(i,N)FOR(j,N)
    {
        while(board[i][j].size()>0)
        {
            Fireball fb = board[i][j].front();
            board[i][j].pop();
            int x = i + fb.s * (dx[fb.d]);
            int y = j + fb.s * (dy[fb.d]);
            if(x>0) x%=N;
            else if(x<0){
                x = N+(x%N);
            }
            if(y>0) y%=N;
            else if(y<0){
                y = N+(y%N);
            }
            if(x==0) x=N;if(y==0) y=N;
            sample[x][y].push(fb);
        }
    }
    FOR(i,N)FOR(j,N)
    {
        while(sample[i][j].size()>0)
        {
            board[i][j].push(sample[i][j].front());
            sample[i][j].pop();
        }
    }
}
void combine()
{
    FOR(i,N)FOR(j,N)
    {
        if(board[i][j].size()>=2)
        {
            int msum = 0;
            int ssum = 0;
            int fcnt = board[i][j].size();
            int evend = 0;
            int oddd = 0;
            while(board[i][j].size()>0)
            {
                msum += board[i][j].front().m;
                ssum += board[i][j].front().s;
                if(board[i][j].front().d%2==0) evend++;
                else oddd++;
                board[i][j].pop();
            }
            for(int k=0; k<4; k++)
            {
                Fireball fb;
                fb.m = msum/5;
                fb.s = ssum/fcnt;
                if(evend==0||oddd==0) fb.d = 2*k;
                else fb.d = 2*k+1;
                if(fb.m>0) board[i][j].push(fb);
            }
        }
    }
}
void start()
{
    move();
    combine();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> K;
    FOR(i,M){
        Fireball fb;
        int x,y; cin >> x >> y;
        cin >> fb.m >> fb.s >> fb.d;
        board[x][y].push(fb);
    }
    while(K--) start();
    int ans = 0;
    FOR(i,N)FOR(j,N) if(board[i][j].size()>0){
        while(board[i][j].size()>0){
            ans+=board[i][j].front().m;
            board[i][j].pop();
        }
    }
    cout << ans;
    return 0;
}