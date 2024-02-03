#include<iostream>
using namespace std;
int N,r,c;
int ans = 0;
void find(int x, int y, int size)
{
    if(x==r&&y==c)
    {
        cout << ans;
        return;
    }else if(r>=x && r<x+size && c>=y && c<y+size)
    {
        find(x,y,size/2);
        find(x,y+size/2,size/2);
        find(x+size/2,y,size/2);
        find(x+size/2,y+size/2,size/2);
    }else ans += size*size;
}
int main()
{
    cin >> N >> r >> c;
    int n = 1;
    int c = 0;
    while(N--) n*=2;
    find(0,0,n);
}