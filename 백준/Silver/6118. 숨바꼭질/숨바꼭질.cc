#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, M;
vector<int> graph[20001];
int visit[20001];
// int dis[20001];
vector<pair<int,int>> v;
struct hutgan{
    int num, distance;
};
bool compare(pair<int,int> a, pair<int,int> b ){
    if(a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}
void search(hutgan h)
{
    queue<hutgan> q1;
    q1.push(h);
    visit[h.num] = 1;
    while(!q1.empty())
    {
        // int c = q1.size();
        // for(int i = 0; i < c; i++)
        // {
        //     q1.push(q1.front());
        //     cout << q1.front() << " "; q1.pop();
        // }
        // cout << endl;

        hutgan h1 = q1.front(); q1.pop();
        // cout << h1.num << endl;
        for(int i = 0; i < graph[h1.num].size(); i++)
        {
            int b = graph[h1.num][i];
            if(visit[b] != 1)
            {
                // cout << "***\n";
                hutgan h2;
                h2.num = b; h2.distance = h1.distance + 1;
                // if(dis[h2.num] > h2.distance)
                v.push_back(make_pair(h2.num,h2.distance));
                    // dis[h2.num] = h2.distance;
                q1.push(h2);
                visit[b] = 1;
            }
        }
    }
}
int main()
{
    cin >> N >> M;  
    for(int i = 1; i <= M; i++)
    {
        int a,b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    hutgan h; h.num = 1; h.distance = 0;
    search(h);
    sort(v.begin(),v.end(),compare);
    cout << v[0].first << " " << v[0].second << " ";
    int count = 0;
    for(int i=0; i<=N; i++)
    {
        if(v[i].second == v[0].second) count++;
    }
    cout << count;
    // for(auto&a : v)
    // {
    //     cout << a.first << " : " << a.second << '\n';
    // }
    // cout << endl;
    // for(int i = 1; i <= N; i++)
    // {
    //     for(int j = 0; j < graph[i].size(); j++)
    //     {
    //         cout << i << "->" << graph[i][j] << endl;
    //     }
    // }
    // for(int i = 1; i <= N; i++)
    // {
    //     cout << i << " : " << dis[i] << endl;
    // }
}