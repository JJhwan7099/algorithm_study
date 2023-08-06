#include <iostream>
#include <vector>
using namespace std;
#define FOR(i,N)for(int i=1;i<=N;i++)
int N;
int ans[3000001];
vector<int> v1[3000001];
int min(int a, int b){if(a==0 && b!=0) return b; if(a!=0&&b==0) return a; if(a>b)return b; else return a;}
void doing(int n, int cnt)
{
    for(int i = 1; i <= N; i++)
    {
        if(i*3 <= N){
            ans[i*3] = min(ans[i*3],ans[i] + 1);
            if(ans[i*3] != ans[i] + 1)
            {
                v1[i*3] = v1[i*3];
            }else{
                v1[i*3] = v1[i]; v1[i*3].push_back(i);
            }
        }
        if(i*2 <= N){
            ans[i*2] = min(ans[i*2],ans[i] + 1);
            if(ans[i*2] != ans[i] + 1)
            {
                v1[i*2] = v1[i*2];
            }else{
                v1[i*2] = v1[i]; v1[i*2].push_back(i);
            }
        }
        if(i+1 <= N)
        {
            ans[i+1] = min(ans[i+1],ans[i] + 1);
            if(ans[i+1] != ans[i] + 1)
            {
                v1[i+1] = v1[i+1];
            }else{
                v1[i+1] = v1[i]; v1[i+1].push_back(i);
            }
        }
    }
}
int main()
{
    cin >> N;
    doing(1,1);
    cout << ans[N] << '\n';
    cout << N << " ";
    for(int i = v1[N].size()-1; i >= 0; i--) 
    {
        if(v1[N][i] > 0 && v1[N][i] <= N)
        cout  << v1[N][i] << " ";
    }
}