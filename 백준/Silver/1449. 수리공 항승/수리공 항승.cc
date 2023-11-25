#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, L;
vector<int> pipe;
int main()
{
    cin >> N >> L;
    for(int i=0; i<N; i++)
    {
        int a; cin >> a;
        pipe.push_back(a);
    }
    sort(pipe.begin(),pipe.end());
    bool check = false;
    int checkval;
    int cnt = 0;
    for(int i=0; i<pipe.size(); i++)
    {
        if(check==false)
        {
            cnt++;
            checkval = pipe[i];
            check=true;
        }else{
            if((pipe[i]+0.5) - (checkval-0.5)<=L)
            {
                continue;
            }else{
                cnt++;
                checkval=pipe[i];
            }
        }
    }
    cout << cnt;
}