#include <iostream>
#include <string>
#include <queue>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N,M;
double K;
char board[250][250];
int Bmark[250][250];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int ddx = -1;
int ddy = 1;
int cx,cy;
int ans = 0;
void break_block(int b, int a) {
    Bmark[b][a] = -1;
    for(int i=0; i<4; i++) {
        int x = a + dx[i];
        int y = b + dy[i];
        
        if((board[y][x]=='.' || board[y][x]=='B') && Bmark[y][x]==1) {
            break_block(y,x);
        }
    }
}
void reflect() {
    if(cx==0) {
        if(ddx == -1) ddx = 1;
        else if(ddx == 1) ddx = -1;
    }
    if(cx==N*2) {
        if(ddx == 1) ddx=-1;
        else if(ddx==-1) ddx=1;
    }
    if(cy==M*2) {
        if(ddy==-1) ddy=1;
        else if(ddy==1) ddy=-1;
    }
}
void start() {
    int cnt = 0;
    while(true) {
        if(board[cy][cx]!='+' && Bmark[cy][cx]==1&&(board[cy][cx]=='-' || board[cy][cx]=='|')) {
            if(board[cy][cx]=='|') {
                if(cx+1<=2*N && board[cy][cx+1]=='B' && Bmark[cy][cx+1]==1) {
                    break_block(cy,cx+1);
                    ans++;
                }
                if(cx-1>=0 && board[cy][cx-1]=='B' && Bmark[cy][cx-1]==1) {
                    break_block(cy,cx-1);
                    ans++;
                }
            }else if(board[cy][cx]=='-') {
                if(cy+1<=2*M && board[cy+1][cx]=='B' && Bmark[cy+1][cx]==1) {
                    break_block(cy+1,cx);
                    ans++;
                }
                if(cy-1>=0 && board[cy-1][cx]=='B' && Bmark[cy-1][cx]==1) {
                    break_block(cy-1,cx);
                    ans++;
                }
            }else if(board[cy][cx]=='.') {
                if(cy+1<=2*M && board[cy+1][cx]=='B' && Bmark[cy+1][cx]==1) {
                    break_block(cy+1,cx);
                    ans++;
                }
                else if(cy-1>=0 && board[cy-1][cx]=='B' && Bmark[cy-1][cx]==1) {
                    break_block(cy-1,cx);
                    ans++;
                }
                else if(cx+1<=2*N && board[cy][cx+1]=='B' && Bmark[cy][cx+1]==1) {
                    break_block(cy,cx+1);
                    ans++;
                }
                else if(cx-1>=0 && board[cy][cx-1]=='B' && Bmark[cy][cx-1]==1) {
                    break_block(cy,cx+1);
                    ans++;
                }
            }
        }
        else if(board[cy][cx]!='+' && Bmark[cy][cx]==1 && board[cy][cx]=='B') {
            break_block(cy,cx);
            ans++;
        }
        if(cnt!=0 && cy==0) break;
        if((cx==0||cx==N*2||cy==M*2)) reflect();
        cnt++;
        cx+=ddx;
        cy+=ddy;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> K;
    K*=2;//0.5의 배수로 입력되기 때문에 전처리
    cx = K;
    cy = 0;
    for(int i=2*M; i>=0; i--) {
        string s; cin >> s;
        for(int k=0; k<s.length(); k++) {
            board[i][k] = s[k];
        }
    }
    //블럭을 가로지르는지 확인하기 위한 전처리
    for(int i=0; i<2*M+1; i++)for(int j=0; j<2*N+1; j++) {
        if(board[i][j]=='B') {
            Bmark[i][j]=1;
            for(int k=0; k<4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                if(x<0||y<0||x>M*2||y>N*2) continue;
                Bmark[x][y]=1;
            }
        }
    }    
    start();
    cout << ans;
    return 0;
}