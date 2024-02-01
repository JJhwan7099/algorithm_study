#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int N,M;
void backtracking(vector<int> v)
{
    
    if(v.size()==M) 
    {
        for(auto&a :v) cout << a << " ";
        cout << '\n';
        return;
    }
    unordered_map<int,int> m;
    for(auto&a: v) m[a]=1;
    for(int i=1; i<=N; i++)
    {
        if(m[i]!=1)
        {
            v.push_back(i);
            backtracking(v);
            v.pop_back();
        }
    }
}
int main()
{
    cin >> N >> M;
    vector<int> v;
    backtracking(v);
}