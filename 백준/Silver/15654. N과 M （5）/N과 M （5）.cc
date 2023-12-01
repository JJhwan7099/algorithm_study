#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,M;
vector<vector<int>> ans;
int num[9];
void start(int n, vector<int> v)
{
    v.push_back(n);
    if(v.size()==M) 
    {
        ans.push_back(v);
        return;
    }
    for(int i=1;i<=N; i++)
    {
        bool check = true;
        for(int j=0; j<v.size(); j++) if(v[j] == num[i]) check = false;
        if(check==true) start(num[i], v);
    }
}
int main()
{
    cin >> N >> M;
    for(int i=0; i<N; i++)
    {
        cin >> num[i+1];
    }
    for(int i=1;i<=N;i++) 
    {
        vector<int> v;
        start(num[i], v);
    }
    sort(ans.begin(),ans.end());
    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++) cout << ans[i][j] << " ";
        cout << '\n';
    }
}