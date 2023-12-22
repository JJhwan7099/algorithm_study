#include <string>
#include <vector>
#include <iostream>
#define FOR(i,N) for(int i=0; i<N; i++)
using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    pair<int,int> s;
    FOR(i,park.size())FOR(j,park[i].length())
    {
        if(park[i][j]=='S'){s={i,j}; break;}
    }
    int x = s.first;
    int y = s.second;
    for(auto&a:routes)
    {
        char d = a[0]; string ddis = "";
        for(int i=2; i<a.length(); i++) ddis+=a[i];
        int dis = stoi(ddis);
        int X = x; int Y = y;
        if(d=='N')
        {
            while(dis--)
            {
                X--;
                if(X<0 || park[X][Y]=='X') {break;}
                else{
                    if(dis==0) {x = X; y = Y;}
                }
            }
        }else if(d=='S')
        {
            while(dis--)
            {
                X++;
                if(X>=park.size() || park[X][Y]=='X') {break;}
                else{
                    if(dis==0) {x = X; y = Y;}
                }
            }
        }else if(d=='W')
        {
            while(dis--)
            {
                Y--;
                if(Y<0 || park[X][Y]=='X') {break;}
                else{
                    if(dis==0) {x = X; y = Y;}
                }
            }
        }else{
            while(dis--)
            {
                Y++;
                if(Y>=park[X].length() || park[X][Y]=='X') {break;}
                else{
                    if(dis==0) {x = X; y = Y;}
                }
            }
        }
        cout << x << " " << y << endl;
    }
    answer.push_back(x); answer.push_back(y);
    return answer;
}