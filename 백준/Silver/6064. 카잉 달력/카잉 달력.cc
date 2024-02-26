#include<iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int T;
int gcd(int a, int b) {//최대 공약수 함수(최소공배수는 a*b / 최대공약수)
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while(T--)
    {
        int M,N,x,y; cin >> M >> N >> x >> y;
        int result = -1;
        int cnt=x;
        int X=x;
        int Y=x;
        int limit = gcd(M,N);
        while(true)
        {
            if(Y>N)
            {
                Y=Y%N;
                if(Y==0) Y=N;
            }
            if(X==x&&Y==y)
            {
                result=cnt;
                break;
            }else if(cnt>M*N/limit) break;
            Y+=M;
            cnt+=M;
        }
        cout << result << '\n';
    }
    return 0;
}