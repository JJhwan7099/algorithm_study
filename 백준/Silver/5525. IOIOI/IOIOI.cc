#include<iostream>
#include<vector>
using namespace std;
#define FOR(i,N) for(int i=1; i<=N; i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    string s = "";
    FOR(i,N*2+1)
    {
        if(i%2==1) s+="I";
        else s+="O";
    }
    int NN;
    cin >> NN;
    string S = "";
    cin >> S;
    vector<int> v;
    for(int i=0; i<S.length(); i++)
    {
        if(S[i]=='I')
        {
            bool b=false;
            int cnt=1;
            i++;
            while(i<S.length())
            {
                if(!b&&S[i]=='O')
                {
                    cnt++;
                    b=true;
                    i++;
                    continue;
                }else if(b&&S[i]=='I')
                {
                    cnt++;
                    b=false;
                    i++;
                    continue;
                }
                break;
            }
            i--;
            if((cnt>=3)||i==S.length()-1) v.push_back(cnt);
        }
    }
    int ans=0;
    for(auto&a:v)
    {
        for(int i=s.length(); i<=a; i+=2) ans++;
    }
    cout << ans;
    return 0;
}