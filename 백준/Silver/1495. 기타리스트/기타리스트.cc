#include<iostream>
#include<vector>
#include<map>
using namespace std;
int N, S, M;
int volume[1000];
vector<int> DP[1000];
int maximum = -1;
int max(int a, int b) 
{
    if(a>b) return a; else return b;
}
void dp()
{
    DP[0].push_back(S);
    // DP[1].push_back(DP[0][0] + volume[1]);
    // DP[1].push_back(DP[0][0] - volume[1]);
    for(int i = 1; i <= N; i++)
    {
        map<int,int>m;
        for(int k = 0; k < DP[i-1].size(); k++)
        {
            if(DP[i-1][k]+volume[i] < 0 || DP[i-1][k]+volume[i] > M)
            {
                continue;
            }
            else
            {
                if(m[DP[i-1][k]+volume[i]] == 0)
                {
                    DP[i].push_back(DP[i-1][k]+volume[i]);
                    m[DP[i-1][k]+volume[i]] = 1;
                }
            }
        }
        for(int k = 0; k < DP[i-1].size(); k++)
        {
            if(DP[i-1][k]-volume[i] < 0 || DP[i-1][k]-volume[i] > M)
            {
                continue;
            }
            else
            {
                if(m[DP[i-1][k]-volume[i]] == 0)
                {
                    DP[i].push_back(DP[i-1][k]-volume[i]);
                    m[DP[i-1][k]-volume[i]] = 1;
                }
            }
        }
        // for(int j = 0; j < DP[i].size(); j++) cout << DP[i][j] << " ";
        // cout << "<-" << i << "size: "<< DP[i].size() << endl;
    }
}
int main()
{
    cin >> N >> S >> M;
    for(int i = 1; i <= N; i++){ cin >> volume[i];}
    dp();
    for(int i = 0; i < DP[N].size(); i++)
    {
        if(DP[N][i] >= 0 && DP[N][i] <= M && maximum < DP[N][i])
        {
            maximum = DP[N][i];
        }
    }
    cout << maximum;
}