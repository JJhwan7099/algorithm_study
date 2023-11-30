#include<iostream>
#include<deque>
#include<vector>
using namespace std;
deque<int> dq[5];
vector<pair<int,int>> v;
int K;
void banclock(deque<int>& a)
{
    a.push_back(a.front());
    a.pop_front();
}
void clock(deque<int>& a)
{
    a.push_front(a.back());
    a.pop_back();
}
int main()
{
    for(int i=0; i<4; i++)
    {
        string s; cin >> s;
        for(int j=0;j<s.length(); j++) dq[i+1].push_back(s[j]-'0');
    }
    cin >> K;
    for(int i=0; i<K; i++)
    {
        int a,b; cin >> a >> b;
        v.push_back({a,b});
    }

    for(int i=0; i<v.size(); i++)
    {
        if(v[i].first==1)
        {
            if(dq[1][2]==dq[2][6])
            {
                if(v[i].second==1) clock(dq[1]);
                else banclock(dq[1]);
                continue;
            }
            else if(dq[2][2]==dq[3][6])
            {
                if(v[i].second==1)
                {
                    clock(dq[1]);
                    banclock(dq[2]);
                }else{
                    banclock(dq[1]);
                    clock(dq[2]);
                }
                continue;
            }
            else if(dq[3][2]==dq[4][6])
            {
                if(v[i].second==1)
                {
                    clock(dq[1]);
                    banclock(dq[2]);
                    clock(dq[3]);
                }else{
                    banclock(dq[1]);
                    clock(dq[2]);
                    banclock(dq[3]);
                }
                continue;
            }
            else
            {
                if(v[i].second==1)
                {
                    clock(dq[1]);
                    banclock(dq[2]);
                    clock(dq[3]);
                    banclock(dq[4]);
                }else{
                    banclock(dq[1]);
                    clock(dq[2]);
                    banclock(dq[3]);
                    clock(dq[4]);
                }
                continue;
            }
        }
        else if(v[i].first==4)
        {
            if(dq[4][6]==dq[3][2])
            {
                if(v[i].second==1) clock(dq[4]);
                else banclock(dq[4]);
                continue;
            }
            else if(dq[3][6]==dq[2][2])
            {
                if(v[i].second==1)
                {
                    clock(dq[4]);
                    banclock(dq[3]);
                }else{
                    banclock(dq[4]);
                    clock(dq[3]);
                }
                continue;
            }
            else if(dq[2][6]==dq[1][2])
            {
                if(v[i].second==1)
                {
                    clock(dq[4]);
                    banclock(dq[3]);
                    clock(dq[2]);
                }else{
                    banclock(dq[4]);
                    clock(dq[3]);
                    banclock(dq[2]);
                }
                continue;
            }else{
                if(v[i].second==1)
                {
                    clock(dq[4]);
                    banclock(dq[3]);
                    clock(dq[2]);
                    banclock(dq[1]);
                }else{
                    banclock(dq[4]);
                    clock(dq[3]);
                    banclock(dq[2]);
                    clock(dq[1]);
                }
                continue;
            }
        }else if(v[i].first==2){
            if(dq[1][2]==dq[2][6])
            {
                if(dq[2][2]==dq[3][6]){
                    if(v[i].second==1) clock(dq[2]);
                    else banclock(dq[2]);
                    continue;
                }else if(dq[3][2]==dq[4][6])
                {
                    if(v[i].second==1) 
                    {
                        clock(dq[2]);
                        banclock(dq[3]);
                    }else{ 
                        banclock(dq[2]);
                        clock(dq[3]);
                    }
                    continue;
                }else{
                    if(v[i].second==1) 
                    {
                        clock(dq[2]);
                        banclock(dq[3]);
                        clock(dq[4]);
                    }else{ 
                        banclock(dq[2]);
                        clock(dq[3]);
                        banclock(dq[4]);
                    }
                    continue;
                }
            }else{
                if(dq[2][2]==dq[3][6]){
                    if(v[i].second==1) 
                    {
                        banclock(dq[1]);
                        clock(dq[2]);
                    }else{ 
                        clock(dq[1]);
                        banclock(dq[2]);
                    }
                    continue;
                }
                else if(dq[3][2]==dq[4][6])
                {
                    if(v[i].second==1) 
                    {
                        banclock(dq[1]);
                        clock(dq[2]);
                        banclock(dq[3]);
                    }else{ 
                        clock(dq[1]);
                        banclock(dq[2]);
                        clock(dq[3]);
                    }
                    continue;
                }else{
                    if(v[i].second==1) 
                    {
                        banclock(dq[1]);
                        clock(dq[2]);
                        banclock(dq[3]);
                        clock(dq[4]);
                    }else{ 
                        clock(dq[1]);
                        banclock(dq[2]);
                        clock(dq[3]);
                        banclock(dq[4]);
                    }
                    continue;
                }
            }
        }else if(v[i].first==3)
        {
            if(dq[3][2]==dq[4][6])
            {
                if(dq[3][6]==dq[2][2]){
                    if(v[i].second==1) clock(dq[3]);
                    else banclock(dq[3]);
                    continue;
                }else if(dq[2][6]==dq[1][2])
                {
                    if(v[i].second==1) 
                    {
                        clock(dq[3]);
                        banclock(dq[2]);
                    }else{ 
                        banclock(dq[3]);
                        clock(dq[2]);
                    }
                    continue;
                }else{
                    if(v[i].second==1) 
                    {
                        clock(dq[3]);
                        banclock(dq[2]);
                        clock(dq[1]);
                    }else{ 
                        banclock(dq[3]);
                        clock(dq[2]);
                        banclock(dq[1]);
                    }
                    continue;
                }
            }else{
                if(dq[3][6]==dq[2][2]){
                    if(v[i].second==1) 
                    {
                        banclock(dq[4]);
                        clock(dq[3]);
                    }else{ 
                        clock(dq[4]);
                        banclock(dq[3]);
                    }
                    continue;
                }
                else if(dq[2][6]==dq[1][2])
                {
                    if(v[i].second==1) 
                    {
                        banclock(dq[4]);
                        clock(dq[3]);
                        banclock(dq[2]);
                    }else{ 
                        clock(dq[4]);
                        banclock(dq[3]);
                        clock(dq[2]);
                    }
                    continue;
                }else{
                    if(v[i].second==1) 
                    {
                        banclock(dq[4]);
                        clock(dq[3]);
                        banclock(dq[2]);
                        clock(dq[1]);
                    }else{ 
                        clock(dq[4]);
                        banclock(dq[3]);
                        clock(dq[2]);
                        banclock(dq[1]);
                    }
                    continue;
                }
            }
        }
    }
    int scr = 0;
    for(int i=0; i<4; i++)
    {
        if(dq[i+1][0]==1)
        {
            if(i+1==1) scr+=1;
            else if(i+1==2) scr+=2;
            else if(i+1==3) scr+=4;
            else if(i+1==4) scr+=8;
        }
    }
    cout << scr;
}