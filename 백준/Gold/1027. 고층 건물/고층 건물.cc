#include<iostream>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)
int N;
int H[51];
int cnt[51]={0,};
void start(int n)
{
    FOR(i,N)
    {
        if(i==n) continue;
        else{
            if(i>n)
            {
                double giwool = (double)(H[i]-H[n])/(i-n);
                bool check = true;
                if(i==n+1) cnt[n]++;
                else{
                    for(int j=n+1;j<i;j++)
                    {
                        if(H[j]>=H[n]+giwool*(j-n))
                        {
                            check = false;
                            break;
                        }
                    }
                    if(check==true) cnt[n]++;
                }
            }else{
                double giwool = (double)(H[n]-H[i])/(n-i);
                bool check = true;
                if(i==n-1) cnt[n]++;
                else{
                    for(int j=i+1;j<n;j++)
                    {
                        if(H[j]>=H[n]-giwool*(n-j))
                        {
                            check = false;
                            break;
                        }
                    }
                    if(check==true) cnt[n]++;
                }
            }
        }
    }
}
int main()
{
    cin >> N;
    FOR(i,N) cin >> H[i];
    FOR(i,N) start(i);
    int ans=0;
    FOR(i,N) ans = max(ans,cnt[i]);
    cout << ans;
}