#include <iostream>
#include <vector>
using namespace std;
int N;
int button[101];
vector<pair<int,int>>v1;
void doing()
{
    for(int i = 0; i < v1.size(); i++)
    {
        int num = v1[i].second;
        if(v1[i].first == 1)//남자일때
        {
            while(v1[i].second <= N)
            {
                if(button[v1[i].second] == 0)
                {
                    button[v1[i].second] = 1;
                }else{
                    button[v1[i].second] = 0;
                }
                v1[i].second += num;
            }
        }else{//여자일떄
            int cnt = 1;
            while(true)//좌우로 몇칸까지 상태가 같은지 체크
            {
                if(v1[i].second-cnt < 1 || v1[i].second+cnt > N) 
                {
                    cnt--;
                    break;
                }
                if(button[v1[i].second-cnt]==button[v1[i].second+cnt]) cnt++;
                else{
                    cnt--;
                    break;
                }
            }
            while(cnt >= 0)//바깥부터 가운데까지 값 변경
            {
                if(button[v1[i].second+cnt] == 0)
                {
                    button[v1[i].second+cnt] = 1;
                    button[v1[i].second-cnt] = 1;
                }else{
                    button[v1[i].second+cnt] = 0;
                    button[v1[i].second-cnt] = 0;
                }
                cnt--;
            }
        }
    }
    return;
}
int main()
{
    cin >> N;
    for(int i=1;i<=N;i++)
    {
        cin >> button[i];
    }
    int SN; cin >> SN;
    for(int i = 0; i < SN; i++)
    {
        int a,b; cin >> a >> b;
        v1.push_back(make_pair(a,b));
    }
    //입력끝
    doing();
    for(int i = 1; i <= N; i++)
    {
        if(i==N)
        {
            cout << button[i]; return 0;
        }
        cout << button[i] << " ";
        if(i % 20 == 0) cout << '\n';
    }
}